#include <stdio.h>

#define N 20
struct student{
	int num;
	char name[N];
	float score;
};

void print_into(struct student * p ,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d:studen num is %d,name is %s,score is %.2f\n",i,p->num,p->name,(*p).score);
		p++;
	}
}

int main()
{
	struct student s1[] = {{1,"chalice",88},{2,"David",99},{3,"Colin",70}};
	
	print_into(s1,sizeof(s1)/sizeof(struct student));
	return 0;
}
