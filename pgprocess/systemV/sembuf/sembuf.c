#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

#define N 64
#define READ 0
#define WRITE 1

void pv(int semid,int num,int op)
{
    struct sembuf buf;
    
    buf.sem_num = num;
    buf.sem_op = op;
    buf.sem_flg = 0;
    semop(semid,&buf,1);
}

union semun{
    int val;
    struct semds_ds *buf;
    unsigned short *arrary;
    struct seminfo *__buf;
};

void init_sem(int semid,int s[],int n)
{
    int i;
    union semun myun;

    for(i=0;i<n;i++)
    {
        myun.val = s[i];
        semctl(semid,i,SETVAL,myun);
    }
}

int main()
{
    int shmid, semid, s[]={0,1};
    pid_t pid;
    key_t key;
    char *shmaddr;
    
    if((key = ftok(".",'s')) == -1)
    {
        perror("ftok");
        exit(-1);
    }

    if ((shmid = shmget(key,N,IPC_CREAT|0666))<0)
    {
        perror("shmget");
        exit(-1);
    }

    if ((semid = semget(key,2,IPC_CREAT|0666))<0)
    {
        perror("semget");
        goto _error1;
    }
    init_sem(semid,s,2);
    if((shmaddr = (char *)shmat(shmid,NULL,0))==(char *)-1)
    {
        perror("shmat");
        goto _error2;
    }
    if((pid = fork())<0)
    {
        perror("fork");
        goto _error2;
    }else if (pid ==0){
        char *p,*q;
        while(1)
        {
            pv(semid,READ,-1);
            p = q = shmaddr;
            while(*q)
            {
                if(*q != ' ')
                {
                    *p++ = *q;
                }
                q++;
            }
            *p = '\0';
            printf("%s",shmaddr);
            pv(semid,WRITE,1);
        }
    }else
    {
        while(1)
        {
            pv(semid,WRITE,-1);
            printf("input > ");
            fgets(shmaddr, N,stdin);
            if(strcmp(shmaddr,"quit\n")==0)
            {
                break;
            }
            pv(semid,READ,1);
        }
    kill(pid,SIGUSR1);
    }
    _error1:
        shmctl(semid,IPC_RMID,NULL);
    _error2:
        semctl(semid,0,IPC_RMID);
    shmdt(shmaddr);
    return 0;
}

