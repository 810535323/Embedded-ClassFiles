#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node{
	datatype data;
	struct node * next;
}nodelist,*linklist;

linklist list_create2();
void list_show();
void list_jose(linklist H,int k,int m);
#endif
