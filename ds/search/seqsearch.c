#include <stdio.h>

#define MAXSIZE 10
int seqsearch(int *a,int key);
int main(void)
{	
	char ch;
	int i,key;
	int  a[MAXSIZE] = {67,4,32,1,5,3,6,22,61,50};
	while(1)
	{	
		printf("pls input key:");
		scanf("%d",&key);
		i = seqsearch(a,key);
		if(i == -1){
			printf("search error\n");
		}else{
			printf("search %d at %d\n",key,i);
		}
		while(getchar() != '\n');
		printf("continue?(Y/y)");
		scanf("%c",&ch);
		if(ch == 'y' || ch == 'Y')
			continue;
		else
			break;
	}
	return 0;
}

int seqsearch(int *a,int key){
	int i;

	for(i = MAXSIZE-1;i>=0;i--)
	{
		if(key == a[i])
			return i;
	}
	return i;
}
