#include <stdio.h>

char *del_space(char * s1)
{
	char *s2=s1,*r=s1;	
	while(*s1)
	{	if(*s1 ==' ')
		{
			s1++;
		}
		else
		{
			*s2=*s1;
			s1++;
			s2++;
		}
	}
	*s2 = '\0';
	return r; 
}

char *link(char *p,const char *r)
{
	char *d=p;
	while(*p)
	{
		p++;
	}
	while(*r)
	{
		*p++=*r++;
	}

	*p='\0';//最后赋值结束
	printf("*d=%s\n",d);
	return d;
}

int main()
{
	char s1[] = "howareyou!",s2[]="fine!";
	char s[] ="h e l l o  th e re!";
	puts(s);
	puts(s1);
	puts(s2);
	link(s2,link(s1,del_space(s)));
	puts(s);
	puts(s1);
	puts(s2);
	return 0;
}
