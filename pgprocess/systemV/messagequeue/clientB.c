#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct{
    long mtype;
    char mtext[64];
}MSG;
#define LEN (sizeof(MSG) - sizeof(long))
#define TypeA 100
#define TypeB 200
int main()
{
    key_t key;
    int msgid;
    MSG buf;
    if((key=ftok(".",'q'))== -1){
        perror("ftok");
        exit(-1);
    }
    if((msgid=msgget(key,IPC_CREAT|0666))<0){
        perror("msgget");
        exit(-1);
    }
    while(1){
        if(msgrcv(msgid,&buf,LEN,TypeB,0)<0){
            perror("msgrcv");
        }
        if(strcmp(buf.mtext,"quit\n")==0){
            msgctl(msgid,IPC_RMID,0);
            exit(0);
        }
        printf("rcv from clientA:%s",buf.mtext);
        buf.mtype=TypeA;
        printf("input >");
        fgets(buf.mtext,64,stdin);
        msgsnd(msgid,&buf,LEN,0);
    }
    return 0;
}

