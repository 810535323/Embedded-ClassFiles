#include <stdio.h>
int main()
{
	int a[] = {5,9,1,6,9,10};
	int i,n;
	void * p;
	

	p=a;
	n=sizeof(a)/sizeof(int);
	for(i=0;i<n;i++)
		printf("%d  ",*((int *)p + i));//a[i]
	puts("");
	return 0;
}
