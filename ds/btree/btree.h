#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char datatype_bt;

typedef struct btreenode{
	datatype_bt data;
	struct btreenode *left,*right;
}btree_node,*btree_pnode;

extern void create_btree(btree_pnode *T);
extern void pre_order(btree_pnode t);
extern void unpre_order(btree_pnode t);
extern void mid_order(btree_pnode t);
extern void post_order(btree_pnode t);
extern void level_order(btree_pnode t);
#endif

