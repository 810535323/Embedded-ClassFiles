#include <stdio.h>
int str_fun(char * p)
{
	int num=0;
	while(*p != '\0')
	{	if(*p<='z'&&*p>='a')
		{
			*p -=' ';
			num++;
		}
		else if(*p<='Z'&&*p>='A')
		{
			*p +=' ';
		}
		p++;}
	return num;
}
int main()
{
	int n;
	char s[] = "wellcometoDOTA2";
	n = str_fun(s);
	printf("n =%d\n",n);
	printf("%s\n",s);
	return 0;
}
