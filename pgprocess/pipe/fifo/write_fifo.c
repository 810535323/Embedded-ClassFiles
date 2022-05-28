#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define N 32
int main()
{
    char buf[N];
    int fpd;
    if((fpd = open("myfifo",O_WRONLY)) < 0)
    {
        perror("open");
        exit(-1);
    }
    printf("myfifo is opened\n");
    while(1)
    {
        fgets(buf,N,stdin);
        if(strcmp(buf,"quit\n")==0)
        {
            break;
        }
    write(fpd,buf,N);
    }
    close(fpd);
    return 0;
}

