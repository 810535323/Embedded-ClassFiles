#ifndef __TCPUDP_NET_
#define __TCPUDP_NET_

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
#include <pthread.h>
#include <signal.h>

#define SERV_PORT 5004
#define MUTICAST_IP_ADDR "235.10.10.3"
#define BACKLOG 5
#define BUFSIZE 64
#define QUIT_STR "quit"
#endif
