#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main()
{
	int k,m;
	printf("please input k,m:\n");
	scanf("%d%d",&k,&m);

	linklist H;
	H=list_create2();
	list_show(H);
	
	list_jose(H,k,m);

	return 0;
}
