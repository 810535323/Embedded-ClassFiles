#include "btree.h"
#include "linkqueue.h"
#include "linkstack.h"

#if 0
btree_pnode creatre_btree(void)
{
	datatype_bt ch;
	btree_pnode new;

	printf("please input char:(# is void)\n");
	scanf("%c",&ch);
	if('#' == ch)
		return NULL;
	else{
		if((new = (btree_pnode)malloc(sizeof(btree_node))) == NULL){
			printf("malloc failed!\n");
			exit(1);
		}
		new->data = ch;
		//创建左子树
		new->left = create_btree();
		//创建右子树
		new->right = create_btree();
	}
}
#endif

void create_btree(btree_pnode *T)
{
	datatype_bt ch;

	scanf("%c",&ch);
	if('#' == ch)
		*T == NULL;
	else{
		if((*T = (btree_pnode)malloc(sizeof(btree_node))) == NULL){
			printf("malloc failed!\n");
			exit(1);
		}
		(*T)->data = ch;
		//创建左子树
		create_btree(&(*T)->left);
		//创建右子树
		create_btree(&(*T)->right);
	}
}

//先序遍历
void pre_order(btree_pnode t)
{
	if(t != NULL){
		//访问根节点
		printf("%c",t->data);
		//先序遍历左子树
		pre_order(t->left);
		//先序遍历右子树
		pre_order(t->right);
	}
}
//先序非递归遍历算法（栈）
void unpre_order(btree_pnode t)
{
	linklist top;//top为指向栈顶节点的指针

	top = linkstack_create();//初始化链栈
	while(t != NULL || !linkstack_empty(top)){
		if(t != NULL){
			printf("%c",t->data);
			if(t->right != NULL)
				linkstack_push(top,t->right);
			t = t->left;
		}else{
			t = linkstack_pop(top);
		}
		
}
}
//中序遍历
void mid_order(btree_pnode t)
{
	if(t != NULL){
		//中序遍历左子树
		mid_order(t->left);
		//访问根节点
		printf("%c",t->data);
		//中序遍历右子树
		mid_order(t->right);
	}

}
//后序遍历
void post_order(btree_pnode t)
{
	if(t != NULL){
		//后序遍历左子树
		post_order(t->left);
		//后序遍历右子树
		post_order(t->right);
		//访问根节点
		printf("%c",t->data);
	}

}
//层次遍历算法（队列）
void level_order(btree_pnode t){
	link_p q;
	init_linkqueue(&q);//初始化链式队列
	
	while(t != NULL){
		//访问t指向的节点数据
		printf("%c",t->data);
		//当t的左指针不为空，则入队
		if(t->left != NULL)
			insert_linkqueue(q,t->left);
		//当t的右指针不为空，则入队
		if(t->right != NULL)
			insert_linkqueue(q,t->right);
		//若队列不为空，则出队
		if(!is_empty_linkqueue(q))
			out_linkqueue(q,&t);
		else
			break;
		}
}	
