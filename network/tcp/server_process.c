#include "net.h"

void cli_data_handle(void *arg);//多线程函数
void sig_child_handle(int signo)
{
    if(SIGCHLD == signo)
    {
        waitpid(-1,NULL,WNOHANG);
    }
}

int main()
{
    int fd = -1,newfd = -1;
    struct sockaddr_in sin;
    
    signal(SIGCHLD,sig_child_handle);

    /*创建fd用于保存socket返回值*/
    if((fd = socket(AF_INET,SOCK_STREAM,0)) < 0 )
    {
        perror("socket");
        exit(1);
    }
    bzero(&sin,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(SERV_PORT);
   // sin.sin_addr.s_addr = inet_addr(SERV_IP_ADDR);//只适用于IPV4
    /*优化1.:让服务器可以绑定在任意服务器上*/
#if 1
    sin.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY代表本机所有网卡的IP
#else
    if( inet_pton(AF_INET, SERV_IP_ADDR,(void *)&sin.sin_addr) != 1)
    {
        perror("inet_pton");
        exit(1);
    }
#endif
    /*绑定*/
    if(bind(fd,(struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        perror("bind");
        exit(1);
    }
    /*调用listen()把主动套接字变为被动套接字*/
    if(listen(fd,BACKLOG) < 0)
    {
        perror("listen");
        exit(1);
    }
    
    printf("server starting...ok!\n");
    /*阻塞直到客户机连接*/
#if 0
    if((newfd = accept(fd,NULL,NULL))<0)
    {
        perror("accept");
        exit (1);
    }
    //上面为简单建立连接
    //下面为建立连接并获取用户IP及端口号(优化2)
    struct sockaddr_in cin;
    socklen_t addrlen = sizeof(cin);
    if((newfd = accept(fd,(struct sockaddr *)&cin,&addrlen))<0)
    {
        perror("accept");
        exit (1);
    }
    char ipv4_addr[16];
    if(inet_ntop(AF_INET,(void *)&cin.sin_addr.s_addr,ipv4_addr,sizeof(cin))==NULL)
    {
        perror("inet_ntop");
        exit(1);
    }
    printf("Client:(%s,:%d)is connected!",ipv4_addr,htons(cin.sin_port));

    /*读写*/
    int ret = -1;
    char buf[BUFSIZE];
    while(1)
    {
        bzero(buf,BUFSIZE);
        do{
            ret = read(newfd, buf, BUFSIZE - 1);
        }while(ret < 0 && EINTR == errno);
        if(ret < 0)
        {
            perror("read");
            exit(1);
        }
        if(!ret)
        {
            break;
        }
        printf("Receive data: %s\n",buf);
        if( !strncasecmp(buf, QUIT_STR, strlen(QUIT_STR)))
        {
            printf("Client is exiting\n");
            break;
        }
    }
    close(newfd);
     /*---------------------------------------优化3.以下采用多线程连接*----------------------------------------------------------*/
    pthread_t tid;
    struct sockaddr_in cin;
    socklen_t addrlen = sizeof(cin);
    while(1){
        if((newfd = accept(fd,(struct sockaddr *)&cin,&addrlen))<0)
        {
            perror("accept");
            exit (1);
        }
        char ipv4_addr[16];
        if(inet_ntop(AF_INET,(void *)&cin.sin_addr.s_addr,ipv4_addr,sizeof(cin))==NULL)
        {
            perror("inet_ntop");
            exit(1);
        }
        printf("Client:(%s:%d)is connected!",ipv4_addr,ntohs(cin.sin_port));
        pthread_create(&tid,NULL,(void *)cli_data_handle,(void *)&newfd);
    }
#else 
    struct sockaddr_in cin;
    socklen_t addrlen = sizeof(cin);
    while(1){
        pid_t pid=-1;
        if((newfd = accept(fd,(struct sockaddr *)&cin,&addrlen))<0)
        {
            perror("accept");
            break;
        }//创建子进程用于处理已经建立连接的客户的交互数据
        if((pid = fork()) < 0)
        {
            perror("fork");
            break;
        }
        if(pid == 0)
        {
            close(fd);
            char ipv4_addr[16];
            if(inet_ntop(AF_INET,(void *)&cin.sin_addr.s_addr,ipv4_addr,sizeof(cin))==NULL)
            {
                perror("inet_ntop");
                break;
            }
            printf("Client:(%s:%d)is connected!",ipv4_addr,ntohs(cin.sin_port));
            cli_data_handle(&newfd);
            return 0;
        }else//若pid > 0
        {
            close(newfd);
        }
    }
#endif 
    close(fd);
    return 0;
}

void cli_data_handle(void *arg)//多线程函数
{
    int newfd =*(int *)arg;

    printf("handler child process: newfd = %d\n",newfd);
    int ret = -1;
    char buf[BUFSIZE];
    while(1)
    {
        bzero(buf,BUFSIZE);
        do{
            ret = read(newfd, buf, BUFSIZE - 1);
        }while(ret < 0 && EINTR == errno);
        if(ret < 0)
        {
            perror("read");
            exit(1);
        }
        if(!ret)
        {
            break;
        }
        printf("Receive data from %d: %s\n",newfd,buf);
        if( !strncasecmp(buf, QUIT_STR, strlen(QUIT_STR)))
        {
            printf("Client(fd = %d) is exiting\n",newfd);
            break;
        }
    }
    close(newfd);
}
