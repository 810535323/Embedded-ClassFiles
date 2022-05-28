#include <stdio.h>
#include <stdlib.h>
int main()
{
	char * p;
	p = (char *)malloc(10* sizeof(char));
	if(p == NULL)
	{	printf("Malloc failed!");
		return 0;
	}
	printf("Malloc pointer=%p\n",p);
	free(p);
	p=NULL;
	return 0;
}
