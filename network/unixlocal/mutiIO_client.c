/*./client unix_domain_file*/
#include "net.h"

void usage(char *s)
{
    printf("\n%s unix_domain_file",s);
}

int main(int argc,char **argv)
{
    int fd = -1;
    struct sockaddr_un sun;
    /*创建fd用于保存socket返回值*/
    if(argc < 2)
    {
        usage(argv[0]);
        exit(1);
    }

    if((fd = socket(AF_LOCAL,SOCK_STREAM,0)) < 0 )
    {
        perror("socket");
        exit(1);
    }
    
    /*连接服务器*/
    bzero(&sun,sizeof(sun));
    sun.sun_family = AF_LOCAL;
    /*确保UNIX_DOMAIN_FILE要先存在*/
    if(access(UNIX_DOMAIN_FILE,F_OK|W_OK) < 0)
    {
        perror("access");
        exit(1);
    }
    strncpy(sun.sun_path,UNIX_DOMAIN_FILE,strlen(UNIX_DOMAIN_FILE));

    /*连接*/
    if(connect(fd,(struct sockaddr *)&sun,sizeof(sun)) < 0)
    {
        perror("connect");
        exit(1);
    }
    printf("UNIX Client started!\n");
    
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

