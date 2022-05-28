#include "sequeue.h"

#if 0
sequeue init_sequeue(){
	sequeue q;

	if((q = (sequeue)malloc(sizeof(sequeue)))== NULL){
		printf("malloc failed");
		return;
	}

	q->front = q->rear = -1;

	return q;	
}
#endif

void init_sequeue(sq *q){

	if((*q = (sq)malloc(sizeof(sequeue)))== NULL){
		printf("malloc failed");
		return;
	}

	(*q)->front = (*q)->rear = MAXSIZE -1;

}

//判断队列是否已满
bool is_full_sequeue(sq q){
	if((q->rear+1)%MAXSIZE == q->front)
		return true;
	else
		return false;
}
bool is_empty_sequeue(sq q){
	if(q->rear == q->front)
		return true;
	else
		return false;
}

//入队烈
bool insert_sequeue(sq q,datatype value){
	
	if(is_full_sequeue(q)){
		printf("队列已满!\n");
		return false;
	}

	q->rear = (q->rear+1)%MAXSIZE;
	q->data[q->rear] = value;
	return true;
}

bool out_sequeue(sq q,datatype *d){
	//判断队列是否为空
	if(is_empty_sequeue(q)){
		printf("队列为空\n");
		return false;
	}
	q->front = (q->front+1)%MAXSIZE;
	*d = q->data[q->front];
	return true;
}

void show_sequeue(sq q){
	int i;
	if(is_empty_sequeue(q)){
		return;	
	}
	for(i = (q->front+1)%MAXSIZE;i != (q->rear+1)%MAXSIZE;i=(i+1)%MAXSIZE){
		printf("%d\t",q->data[i]);
	}
	puts("");
}
