#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#include <stdlib.h>
#include <stdio.h>

typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next;
}listnode, *linklist;

linklist linkstack_create();
int linkstack_empty(linklist s);
void linkstack_clear(linklist s);
int linkstack_push(linklist s,datatype value);
datatype linkstack_pop(linklist s);
datatype linkstack_top(linklist s);
void linkstack_free(linklist s);

#endif
