#include "sqstack.h"

int main()
{
	sqstack * s;
	int n;
loop:
	printf("please input full-stack-numbers:\n");
	scanf("%d",&n);
	if(n<=-1)
	{	
		printf("wrong!");
		goto loop;
	}
	s= stack_create(n);

	stack_push(s,10);
	stack_push(s,20);
	stack_push(s,30);
	stack_push(s,40);
	while(!stack_empty(s)){
		printf("%d\n",stack_pop(s));
	}
	puts("");
	stack_free(s);

#if 0	
	free(s->data);
	s->data = NULL;
	free(s);
	s = NULL;
	return 0;
#endif 
}

