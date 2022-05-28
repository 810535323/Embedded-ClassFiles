#include <stdio.h>

int flib(int n)
{
	if(n==0||n==1)
		return 1;
	return flib(n-1)+flib(n-2);
}
int main()
{
	int n=0;
	while(n<=12)
	{	printf("month%d=%d\n",n,flib(n));
		n++;
	}
	return 0;
}
