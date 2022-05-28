#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch1[] = "Hello World!";
	char ch2[] = "Hello World!";

	char *p;
	
	p = ch1;

	if(isalpha(*p))
	{
		if(isupper(*p))
		
			*p = tolower(*p);
		
		else
			*p = toupper(*p);
	}
	
	printf("%s,%p\n",p,p);
	
	p = ch2;
	printf("%s,%p\n",p,p);
}
