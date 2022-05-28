#include <stdio.h>

#define N 10
void show(int a[]);
void shellsort(int a[]);

int main(void)
{
	int a[] = {35,13,54,87,98,15,65,32,7,67};
	printf("原无序记录如下：\n");
	show(a);
	printf("排序过程如下：\n");
	shellsort(a);
	return 0;

}

void show(int a[])
{
	int i;
	for(i = 0;i < N;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

void shellsort(int a[])
{
	int temp,i,j;
	int d;
	for(d = N/2; d > 0; d /= 2)//希尔排序 有点：跳跃式排序 降低移动次数
	{
		for(i = d;i < N; i++)
		{
			temp = a[i];
			for(j = i-d;j >= 0; j -= d )
				if(temp < a[j])
					a[j+d] = a[j];
				else 
					break;
			a[j+d] = temp;
		}
		show(a);
	}
}

