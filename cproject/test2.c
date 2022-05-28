#include <stdio.h>
int main()
{
	int i,a=0;
	for(i=0;i<11;i++)
	{
		a=a+i;
	}
	printf("%s,%s,%da=%d\n",__FILE__,__FUNCTION__,__LINE__,a);
	return 0;
}
