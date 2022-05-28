#include <net.h>

int main()
{
    fd_set reset;
    int maxfd = -1;

    struct timeval t_out;

    fd = socket(...);
    bind(fd,...);
    listen(fd,...);

    while(1)
    {
        maxfd = fd;
        FD_ZERO(&reset);

        FD_SET(fd,&reset);
        //依次把已经建立好连接fd加入到集合中，记录下来最大的文件maxfd
        //...
    #if 0
        select(maxfd+1,&reset,NULL,NULL,NULL);
    #else
        t_out.tv_sec = 5;
        t_out.tv_usec = 0;
        select(maxfd+1,&reset,NULL,NULL,&t_out);
    #endif 
        if(FD_ISSET(fd,&rset))
        {
            newfd = accept(fd,...);
        }

        //依次判断已经建立连接的客户端是否有数据
    }
        return 0;
}

