#include "btree.h"

int main(void){
	btree_pnode t;

	create_btree(&t);//创建二叉树

	printf("先序遍历序列:");
	pre_order(t);
	puts("");
	printf("先序非递归遍历序列:");
	unpre_order(t);
	puts("");
	printf("中序遍历序列:");
	mid_order(t);
	puts("");
	printf("后序遍历序列:");
	post_order(t);
	puts("");
	printf("层次遍历序列:");
	level_order(t);
	puts("");
	return 0;
}
