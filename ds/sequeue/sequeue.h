#ifndef _SEQUEUE_H_
#define _SEQUEUE_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10

typedef int datatype; //定义数据类型为int
typedef struct seqqueue{
	datatype ata[MAXSIZE];
	int front,rear;
}sequeue,*sq;

//sequeue init_sequeue();
extern void init_sequeue(sq *q);
extern bool is_full_sequeue(sq q);
extern bool insert_sequeue(sq q,datatype value);
extern bool out_sequeue(sq q,datatype *d);
extern bool is_empty_sequeue(sq q);
extern void show_sequeue(sq q);
#endif
