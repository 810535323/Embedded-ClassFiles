#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

typedef btree_pnode datatype_ls;
typedef struct node
{
	datatype_ls data;
	struct node *next;
}listnode, *linklist;

linklist linkstack_create();
int linkstack_empty(linklist s);
//void linkstack_clear(linklist s);
void linkstack_push(linklist s,datatype_ls value);
datatype_ls linkstack_pop(linklist s);
datatype_ls linkstack_top(linklist s);
//void linkstack_free(linklist s);
#endif
