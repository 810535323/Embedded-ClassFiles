/*
 *用链式队列实现如下功能：用户从键盘输入证书，程序将其入队，用户输入字符，程序将队头元素出队，并在每一次入队和出队之后打印队列元素。
 * */
#include "linkqueue.h"

int main()
{
	link_p q;
	datatype data,t;
	int ret;

	init_linkqueue(&q);

	while(1){
		printf("清输入一个整数:");
		ret = scanf("%d",&data);
		//输入整数时入队
		if(ret == 1){
			if(insert_linkqueue(q,data))
			{
				show_linkqueue(q);
			}
		}else{	//输入字符时出队
			if(out_linkqueue(q,&t)){
				printf("out:%d\n",t);
				show_linkqueue(q);
			}
		//clear
			while(getchar()!='\n');	
		}
	}
	return 0;	
}
