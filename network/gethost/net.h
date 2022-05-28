#ifndef __NET_H__
#define __NET_H__

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
#include <sys/wait.h>

#define SERV_PORT 5001
#define SERV_IP_ADDR "192.168.1.147"
#define BACKLOG 5
#define BUFSIZE 64
#define QUIT_STR "quit"
#endif
