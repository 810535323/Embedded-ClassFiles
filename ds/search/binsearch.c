#include <stdio.h>

#define MAXSIZE 12
int binsearch(int *a,int key);//1.记录必须有序 2.查找效率高 
int main(void)
{	
	char ch;
	int i,key;
	int  a[MAXSIZE] = {3,12,18,20,32,55,60,68,80,86,90,100};
	while(1)
	{	
		printf("pls input key:");
		scanf("%d",&key);
		i = binsearch(a,key);
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

int binsearch(int *a,int key){
	int low,high,mid;

	low = 0;high = MAXSIZE -1;
	while(low <= high)
	{
		mid = (low + high) / 2;//查找中间位置
		if(a[mid] == key)
			return mid;
		else if(a[mid] > key)//查找成功
			high = mid - 1;//如果key <middle 位置,则high = mid-1;
		else 
			//如果key <middle 位置,则high = mid-1;
			low = mid + 1;
	}
	return -1;//查找失败
}
