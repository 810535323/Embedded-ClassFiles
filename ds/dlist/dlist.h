#ifndef _DLIST_H_
#define _DLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node * prior;
	struct node * next;
}dlistnode;

dlistnode * dlist_create();
void dlist_show(dlistnode * H);
dlistnode * dlist_get(dlistnode * H,int pos);
int dlist_insert(dlistnode * H,int value,int pos);
int dlist_delete(dlistnode * H,int pos);
#endif
