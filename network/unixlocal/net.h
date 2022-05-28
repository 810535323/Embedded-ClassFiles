#ifndef __mutiIO_NET_H__
#define __mutiIO_NET_H__

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
#include <sys/select.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/un.h>
//#define SERV_PORT 5001
#define SERV_RESP_STR "Server:"
//#define SERV_IP_ADDR "192.168.1.147"
#define BACKLOG 5
#define BUFSIZE 64
#define QUIT_STR "quit"
#define UNIX_DOMAIN_FILE "/tmp/my_domain_file.1"

#endif
