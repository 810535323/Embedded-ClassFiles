#include "net.h"

int main()
{
    int fd = -1;
    struct sockaddr_in sin;
    /*创建fd用于保存socket返回值*/

    if((fd = socket(AF_INET,SOCK_DGRAM,0)) < 0 )
    {
        perror("socket");
        exit(1);
    }
    
    /*允许地址快速重用*/
    int b_reuse = 1;
    setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&b_reuse,sizeof(int));
    
    /*加入多播组*/
    struct ip_mreq mreq;
    bzero(&mreq,sizeof(mreq));
    mreq.imr_multiaddr.s_addr = inet_addr(MUTICAST_IP_ADDR);
    mreq.imr_interface.s_addr = INADDR_ANY;

    setsockopt(fd, IPPROTO_IP,IP_ADD_MEMBERSHIP, &mreq,sizeof(mreq));
    /*清空数组*/
    bzero(&sin,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(SERV_PORT);
    
    /*让服务器可以绑定在任意服务器上*/
    sin.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY代表本机所有网卡的IP
    /*绑定*/
    if(bind(fd,(struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        perror("bind");
        exit(1);
    }
    printf("BROADCAST START!\n");
    char buf[BUFSIZE];
    struct sockaddr_in cin;
    socklen_t addrlen = sizeof(cin);
    while(1)
    {   
        bzero(buf,BUFSIZE);
        if((recvfrom(fd,buf,BUFSIZE - 1,0,(struct sockaddr *)&cin,&addrlen)) < 0)
        {
            perror("recvfrom");
            continue;
        }
        char ipv4_addr[16];
        if(inet_ntop(AF_INET,(void *)&cin.sin_addr.s_addr,ipv4_addr,sizeof(cin))==NULL)
        {
            perror("inet_ntop");
            exit(1);
        }
        printf("Recived  multicast from(%s:%d):%s",ipv4_addr,ntohs(sin.sin_port),buf);

        if( !strncasecmp(buf, QUIT_STR, strlen(QUIT_STR)))
        {
            printf("Client(%s:%d) is exiting\n",ipv4_addr,ntohs(sin.sin_port));
            break;
        }
    }
    
    return 0;
}

