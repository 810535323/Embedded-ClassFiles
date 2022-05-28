#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

linklist list_create()  //第一种创建方式
{
	linklist H;
	if((H=(linklist)malloc(sizeof(linklist)))==NULL)
	{
		printf("malloc1 failed!\n");
		return H;
	}
	H->data=0;
	H->next=NULL;
	return H;
}

linklist list_create2() //输入数字创建列表
{
	linklist H, r, p;
	
	int value;
	
	if((H=(linklist)malloc(sizeof(linklist)))==NULL)
	{
		printf("malloc1 failed!\n");
		return H;
	}
	H->data=0;
	H->next=NULL;
	r=H;

	while(1){
		printf("input a number:-1 exit\n");
		scanf("%d",&value);
		if(value==-1)
		{
			break;
		}
	if((p=(linklist)malloc(sizeof(linklist)))==NULL)
	{
		printf("malloc1 failed!\n");
		return H;
	}
	p->data=value;
	p->next=NULL;
	r->next=p;
	r=p;
	}
	return H;
}

linklist list_get(linklist H,int pos)  //获取列表中某个位置的数据
{
	linklist p =H;
	int i=-1;
	if(pos<0)
	{
		printf("position is invalid:<0\n");
		return NULL;
	}
	while(p->next && i<pos)
	{
		p=p->next;
		i++;
	}
	if(i == pos)
	{
		return p;
	}else
	{
		printf("position is invalid:> length\n");
		return NULL;
	}
}

linklist list_locate(linklist H,datatype value) //定位输入的第一个数字的位置
{
	linklist p=H->next;
	while(p&&p->data!=value)
	{
		p=p->next;
	}
	return p;
}

void list_show(linklist H)  //显示列表数据
{
	while(H->next)
	{
		printf("%d\n",H->next->data);
		H = H->next;
	}
	printf("\n");
}

int list_head_insert(linklist H,datatype value) //从头部插入数据
{
	linklist p;
	if((p=(linklist)malloc(sizeof(nodelist)))==NULL)
	{
		printf("malloc2 failed!\n");
		return -1;	
	}
	p->data=value;
	p->next=H->next;
	H->next=p;
	return 0;
}

int list_insert(linklist H,int pos,datatype value) //列表某个位置插入数据
{
	linklist p,q;
	if(pos == 0)
	{
		p=H;
	}else
	{
		p=list_get(H,pos-1);
	}
	if (p==NULL)
	{
		printf("para is invalid\n");
		return -1;
	}else
	{
		if((q=(linklist)malloc(sizeof(nodelist)))==NULL)
		{
			printf("malloc failed!\n");
			return -1;
		}
		q->data=value;
		q->next=p->next;
		p->next=q;
		return 0;
	}
}

int list_delete(linklist H,int pos) //删除某个位置的数据
{
	linklist p,q;
	if(pos == 0)
	{
		p=H;
	}else{
		p=list_get(H,pos-1);
	}
	if(p && p->next)
	{
		q=p->next;p->next=q->next;free(q);return 0;
	}else return -1;
}

int list_order_insert(linklist H,datatype value) //顺序插入数据
{
	linklist p,q;

	if((p=(linklist)malloc(sizeof(nodelist)))==NULL)
	{
		printf("malloc failed!\n");
		return -1;
	}
	p->data=value;
	q=H;
	while(q->next && q->next->data <value)
	{
		q=q->next;
	}
	p->next = q->next;
	q->next = p;
	return 0;
}
void list_reverse(linklist H) //列表倒置
{
	linklist p,q;
	p = H->next;
	H->next = NULL;

	while(p)
	{
		q=p;
		p=p->next;

		q->next=H->next;
		H->next=q;
	}
}

void list_sort(linklist H)
{
	linklist r,p,q;

	p=H->next;
	H->next=NULL;

	while(p)
	{
		q=p;
		p=p->next;

		r=H;
		while(r->next &&r->next->data < q->data)
		{
			r=r->next;
		}

		q->next =r->next;
		r->next =q;
	}
}
