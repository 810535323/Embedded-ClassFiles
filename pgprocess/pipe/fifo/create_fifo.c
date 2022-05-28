#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
int main()
{
    if(mkfifo("myfifo",0666) < 0)
    {
        perror("mkfifo");
        exit(-1);
    }
    return 0;
}
