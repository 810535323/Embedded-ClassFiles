#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"

int main()
{
	int i;
	seqlist_t * L=NULL;
	L=create_seqlist();
	for(i=0;i<=4;i++)
		insert_seqlist(L,i,0);
	printf("seqlist length is %d\n",get_length_seqlist(L));
	show_seqlist(L);
	puts("================================================");
	puts("search data = 3");
	printf("data 3's pos is %d\n",search_seqlist(L,3));
	show_seqlist(L);
	puts("================================================");
	puts("delete data 3");
	delete_seqlist(L,search_seqlist(L,3));
	printf("seqlist length is %d\n",get_length_seqlist(L));
	show_seqlist(L);
	puts("================================================");
	puts("change data[2]=99");
	change_seqlist(L,99,2);
	show_seqlist(L);
	puts("================================================");

	clear_seqlist(L);	
}
