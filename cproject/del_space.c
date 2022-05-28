#include <stdio.h>
void del_space(char * s1)
{
	char *s2;
	s2=s1;
	while(*s1)
	{	if(*s1 ==' ')
		{
			s1++;
		}
		else
		{
			*s2++=*s1++;
		}
	}
	*s2 = '\0';
	
}
int main()
{
	char s[] ="u at yvf nv ch ud  uasd  asd  sad  sa ";
	puts(s);
	del_space(s);
	puts(s);
	return 0;
}
