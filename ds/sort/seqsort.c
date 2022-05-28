#include <stdio.h>

#define N 8
void show(int a[]);
void seqsort(int a[]);

int main(void)
{
	int a[] = {35,13,54,87,98,15,65,32};
	printf("原无序记录如下：\n");
	show(a);
	printf("排序过程如下：\n");
	seqsort(a);
	return 0;

}

void show(int a[])
{
	int i;
	for(i = 0;i < N;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

void seqsort(int a[])
{
	int temp,i,j;
	for(i = 1;i < N; i++)
	{
		temp = a[i];
		for(j = i-1;j >= 0; j--)
			if(temp < a[j])
				a[j+1] = a[j];
			else 
				break;
			a[j+1] = temp;
			show(a);
	}
}

