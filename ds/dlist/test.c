#include "dlist.h"

int main()
{
        dlistnode * H,* p;
	int pos;
        H = dlist_create();
        dlist_show(H);
	
	while(1)
	{
		printf("please input pos:");
		scanf("%d",&pos);
		//dlist_insert(H, 100, pos);
        	dlist_delete(H,pos);
		dlist_show(H);

	#if 0	
		p = dlist_get(H,pos);
		if(p){
			printf("%d\n",p->data);
		}
	#endif
	}
        return 0;
}                   
