#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main()
{
    pid_t pid1,pid2;

    char buf[32];
    int pdf[2];

    if(pipe(pdf) < 0)
    {
        perror("pipe");
        exit(-1);
    }
    if((pid1 = fork() < 0))
    {
        perror("fork");
        exit(2);
    }
    else if (pid1 == 0)
    {
        strcpy(buf,"i m process 1");
        write(pdf[1],buf,32);
        exit(0);
    }
    else
    {
        if((pid2=fork())<0)
        {
            perror("fork");
            exit(-1);
        }
        else if(pid2 == 0)
        {
            sleep(1);
            strcpy(buf,"i m process 2");
            write(pdf[1],buf,32);
            printf("%s\n",buf);
        }
    }
    return 0;
}

