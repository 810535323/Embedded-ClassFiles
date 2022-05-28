#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int datatype; //定义数据类型为int

//定义链式对列节点
typedef struct linkqnode{
	datatype data;
	struct linkqnode *next;
}linkq,*linkq_p;

//将front与rear指针封装
typedef struct linkpnode{
	linkq_p front,rear;
}linkp,*link_p;

//linkqueue init_linkqueue();
extern void init_linkqueue(link_p *q);
extern bool insert_linkqueue(link_p q,datatype value);
extern bool out_linkqueue(link_p q,datatype *d);
extern bool is_empty_linkqueue(link_p q);
extern void show_linkqueue(link_p q);
#endif
