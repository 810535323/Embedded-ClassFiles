#include "linkstack.h"

linklist linkstack_create(){
	linklist s;

	if((s = (linklist)malloc(sizeof(listnode)))== NULL){
		printf("malloc failed!");
		return NULL;
	}
	s->next = NULL;
	return s;
}

int linkstack_empty(linklist s){
	return (s->next ==NULL?1:0);
}

void linkstack_clear(linklist s){
	linklist p;

	printf("clear:");
	p = s->next;
	while(p){
		s->next = p->next;
		printf("%d ", p->data);
		free(p);
		p = s->next;
	}
	puts("");
}

int linkstack_push(linklist s,datatype value){
	linklist p;

	if((p = (linklist)malloc(sizeof(listnode))) == NULL){
		printf("malloc failed\n");
		return -1;
	}
	p->data = value;
	p->next = s->next;
	s->next = p;
	return 0;
}

datatype linkstack_pop(linklist s){
	linklist p;
	datatype ret;

	p = s->next;
	s->next = p->next;
	ret = p->data;
	free(p);
	p = NULL;

	return ret;
}

datatype linkstack_top(linklist s){
	return (s->next->data);
}

void linkstack_free(linklist s){
	linklist p;
	
	p = s;
	printf("clear:");
	while(p){
		s = s->next;
		printf("%d ",p->data);
		free(p);
		p = s;
	}
	puts("");
}
