#include <stdio.h>
double power(double x,int n)
{
	int i;
	double r=1;
	for(i=0;i<n;i++)
		r*=x;
	return r;
}
int main()
{
	double x,ret;
	int n;
	printf("please input:x,n\n");
	scanf("%lf%d",&x,&n);
	ret = power(x,n);
	printf("ouput:%lf %d = %lf",x,n,ret);
	return 0;
}
