/*./client serv_name serv_port*/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>

#define SERV_PORT 5001
#define SERV_IP_ADDR "192.168.1.147"
#define BACKLOG 5
#define BUFSIZE 64
#define QUIT_STR "quit"

void usage(char *s)
{
    printf("\n%s serv_ip serv_port",s);
    printf("\n\t serv_name:domain name or serv_ip address");
    printf("\n\t serv_port:server port(>5000)\n\n");
}

int main(int argc,char **argv)
{
    int fd = -1;
    struct sockaddr_in sin;
    struct hostent *hs = NULL;
    int port;
    /*创建fd用于保存socket返回值*/
    if(argc != 3)
    {
        usage(argv[0]);
        exit(1);
    }

    port = atoi (argv[2]);
    
    if(port < 5000)
    {
        usage(argv[0]);
        exit(1);
    }

    if((hs = gethostbyname(argv[1])) == NULL)
    {
        herror("gethostbyname");
        exit(1);
    }

    if((fd = socket(AF_INET,SOCK_STREAM,0)) < 0 )
    {
        perror("socket");
        exit(1);
    }
    
    /*连接服务器*/
    bzero(&sin,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    
    sin.sin_addr.s_addr = *(uint32_t *)hs->h_addr;//只适用于IPV4
    endhostent();
    hs = NULL;
#if 0   
    if(inet_pton(AF_INET, argv[1],(void *)&sin.sin_addr) != 1)
    {
        perror("inet_pton");
        exit(1);
    }
#endif
    /*连接*/
    if(connect(fd,(struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        perror("connect");
        exit(1);
    }
    
    /*读写数据*/
    char buf[BUFSIZE];
    while(1)
    {
        bzero(buf,BUFSIZE);
        if(fgets(buf, BUFSIZE -1,stdin) == NULL)
        {
            continue;
        }
        write(fd, buf,strlen(buf));
        if( !strncasecmp(buf, QUIT_STR, strlen(QUIT_STR)))
        {
            printf("Client is exiting\n");
            break;
        }
    }
    /*关闭套接字*/
    close(fd);
    return 0;
}

