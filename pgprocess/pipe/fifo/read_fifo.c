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
    if((fpd = open("myfifo",O_RDONLY)) < 0)
    {
        perror("open");
        exit(-1);
    }
    printf("myfifo is opened\n");
    while(read(fpd,buf,N)>0)
    {
        printf("the length of string is %ld\n",strlen(buf));
    }
    close(fpd);
    return 0;
}

