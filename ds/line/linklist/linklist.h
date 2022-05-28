#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef int datatype;

typedef struct node{
	datatype data;
	struct node * next;
}nodelist,*linklist;

linklist list_create();
linklist list_create2();
linklist list_get(linklist H,int pos);
linklist list_locate(linklist H,datatype value);
void list_show();
int list_head_insert(linklist H,datatype value);
int list_insert(linklist H,int pos,datatype value);
int list_order_insert(linklist H,datatype value);
int list_delete(linklist H,int pos);
void list_reverse(linklist H);
void list_sort(linklist H);
#endif
