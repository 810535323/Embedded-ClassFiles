#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main()
{
	linklist H;
	//int n,m;
	H=list_create2();
#if 0	
	H=list_create();
	list_head_insert(H,10);
	list_head_insert(H,20);
	list_head_insert(H,30);
	list_head_insert(H,40);
	list_head_insert(H,50);
	list_head_insert(H,60);
#endif
#if 0
	printf("please input pos:");
	scanf("%d",&n);
	if((p=list_get(H,n))!= NULL)
		printf("node data:%d\n",p->data);
#endif

#if 0	
	printf("please input value:");
	scanf("%d",&n);
	if((p=list_locate(H,n))!= NULL)
	{	
		printf("found:%d\n",p->data);
	}else{
		printf("not found,data invalid!\n");
		return 0;
	}
#endif

#if 0	
	printf("please input value:");
	scanf("%d",&n);
	if(list_insert(H,n,90) == -1)
	{	
		printf("insert failed\n");
	}
	list_show(H);
	printf("please delete one number\n");
	scanf("%d",&m);
	list_delete(H,m);
#endif
        //list_reverse(H);
	list_sort(H);
	list_show(H);
	list_order_insert(H,5);
	list_order_insert(H,35);
	list_order_insert(H,75);
	list_show(H);
	return 0;
}
