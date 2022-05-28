#include "linkstack.h"

int main()
{
	linklist s;

	s = linkstack_create();
	
	linkstack_push(s,20);
	linkstack_push(s,10);
	linkstack_push(s,80);
	linkstack_push(s,90);	
	
//	linkstack_free(s);
	//linkstack_clear(s);
	while(!linkstack_empty(s)){
		printf("out:%d\n", linkstack_pop(s));
	}
	puts("");
	return 0;
}
