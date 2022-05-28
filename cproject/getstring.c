#include <stdio.h>
#include <string.h>
//char str[20];
char * getstr()
{
	static char str[20];//函数运行结束会清空内存所以无法返回值
	//char * str="hello";
	strcpy(str,"hello");
	return str;
}

int main()
{
	//char *r;
	//r=getstr();
	printf("---%s---\n",getstr());
	//*(r)++;
	//puts(r);
	return 0;
}
