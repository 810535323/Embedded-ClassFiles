#include "linkqueue.h"

#if 0
linkqueue init_linkqueue(){
	linkqueue q;

	if((q = (linkqueue)malloc(sizeof(linkqueue)))== NULL){
		printf("malloc failed");
		return;
	}

	q->front = q->rear = -1;

	return q;	
}
#endif

void init_linkqueue(link_p *q){
	//申请front和rear的空间
	if((*q = (link_p)malloc(sizeof(linkp)))== NULL){
		printf("malloc failed");
		return;
	}
	//申请头节点空间
	if(((*q)->front = (linkq_p)malloc(sizeof(linkq)))== NULL){
		printf("malloc failed");
		return;
	}
	(*q)->front->next =NULL;
	(*q)->rear = (*q)->front ;

}

bool is_empty_linkqueue(link_p q){
	if(q->rear == q->front)
		return true;
	else
		return false;
}

//入队烈
bool insert_linkqueue(link_p q,datatype value){
	linkq_p p;	
	if((p = (linkq_p)malloc(sizeof(linkq)))== NULL){
		printf("malloc failed");
		return false;
	}
	p->data = value;
	p->next = q->rear->next;
	q->rear->next = p;
	q->rear = q->rear->next;
	return true;
}

bool out_linkqueue(link_p q,datatype *d){
	//判断队列是否为空
	linkq_p t;
	if(is_empty_linkqueue(q)){
		printf("队列为空\n");
		return false;
	}
	t = q->front;
	q->front = q->front->next;
	*d = q->front->data;
	free(t);
	return true;
}
#if 0
void show_linkqueue(link_p q){
	
	linkq_p p;
	if(is_empty_linkqueue(q)){
		return;	
	}
	for(p = q->front->next;p != NULL;p = p->next){
		printf("%d\t",p->data);	
		}
	puts("");
}
#endif
