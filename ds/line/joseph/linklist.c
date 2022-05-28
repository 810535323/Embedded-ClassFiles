#include "linklist.h"

linklist list_create2()
{
	linklist H, r, p;
	
	int n,i;

loop:
	printf("please input n:\n");
	scanf("%d",&n);
	if(n<0){
		printf("n > 0\n");
		goto loop;
	}

	if((H=(linklist)malloc(sizeof(linklist)))==NULL)
	{
		printf("malloc1 failed!\n");
		return H;
	}
	H->data= 1;
	H->next= H;
	r = H;

	for(i=2;i<=n;i++){
	if((p=(linklist)malloc(sizeof(linklist)))==NULL)
	{
		printf("malloc1 failed!\n");
		return H;
	}
	p->data = i;
	r->next = p;
	r =  p ; 
	}
	p->next = H;
	return H;
}


void list_show(linklist H)  //显示列表数据
{	linklist p = H;

	while(p->next != H)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
	printf("%d ", p->data);
}

void list_jose(linklist H,int k,int m)
{
	linklist r,p;
	int i;

	r=H;

	while(r->next->data != k)
	{
		r = r->next;
	}
	printf("k=%d\n",k);
	while(r->next != r){
		for(i = 0;i < m-1;i++){
			r = r->next;
		}
		p = r->next;
		r->next = p->next;
		printf("%d\n",p->data);
		free(p);
		p = NULL;
	}
	printf("%d\n",r->data);
	free(r);
	r = NULL;
}
