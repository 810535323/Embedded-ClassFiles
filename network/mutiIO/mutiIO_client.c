/*./client serv_ip serv_port*/
#include "net.h"

void usage(char *s)
{
    printf("\n%s serv_ip serv_port",s);
    printf("\n\t serv_ip:serv_ip address");
    printf("\n\t serv_port:server port(>5000)\n\n");
}

int main(int argc,char **argv)
{
    int fd = -1;
    struct sockaddr_in sin;
    int port;
    /*创建fd用于保存socket返回值*/
    if(argc != 3)
    {
        usage(argv[0]);
        exit(1);
    }

    if((fd = socket(AF_INET,SOCK_STREAM,0)) < 0 )
    {
        perror("socket");
        exit(1);
    }
    
    port = atoi(argv[2]);
    if(port < 5000)
    {
        usage(argv[0]);
        exit(1);
    }
    /*连接服务器*/
    bzero(&sin,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
   // sin.sin_addr.s_addr = inet_addr(SERV_IP_ADDR);//只适用于IPV4
    
    if(inet_pton(AF_INET, argv[1],(void *)&sin.sin_addr) != 1)
    {
        perror("inet_pton");
        exit(1);
    }

    /*连接*/
    if(connect(fd,(struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        perror("connect");
        exit(1);
    }
    printf("Client started!\n");
    
    /*IO多路复用*/
    fd_set rset;
    char buf[BUFSIZE];
    int ret = -1;
    int maxfd= -1;
    struct timeval t_out;
    while(1)
    {
        FD_ZERO(&rset);
        FD_SET(0,&rset);
        FD_SET(fd,&rset);
        maxfd = fd;

        t_out.tv_sec = 5;
        t_out.tv_usec = 0;

        select(maxfd+1,&rset,NULL,NULL,&t_out);
        if(FD_ISSET(0,&rset))//标准键盘输入
        {//读取键盘输入，发送到网络套接字fd
            bzero(buf,BUFSIZE);
            do{
                ret = read(0,buf,BUFSIZE - 1);
            }while(ret < 0 && EINTR == errno);
            if(ret < 0)
            {
                perror("read");
                continue;
            }
            if(!ret)continue;
            if(write(fd,buf,strlen(buf))<0)
            {
                perror("write");
                continue;
            }
            if(!strncasecmp(buf,QUIT_STR,strlen(QUIT_STR)))
            {
                printf("Client is exited!\n");
                break;
            }
        }
        if(FD_ISSET(fd,&rset))//服务器发送过来的数据
        {//读取套接字数据，处理
            bzero(buf,BUFSIZE);
            do{
                ret = read(fd,buf,BUFSIZE - 1);
            }while(ret < 0 && EINTR == errno);
            if(ret < 0)
            {
                perror("read from socket");
                continue;
            }
            if(!ret)continue;
            
            printf("Server said:%s\n",buf);
            if((strlen(buf) > strlen(SERV_RESP_STR)) && (!strncasecmp(buf+strlen(SERV_RESP_STR),QUIT_STR,strlen(QUIT_STR))))
            {
                printf("Client is exited!\n");
                break;
            }

        }
    }
    close(fd);
    return 0;
}

