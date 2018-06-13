#include <stdio.h>
//malloc
#include <stdlib.h>

#include <string.h>
#include "../random_set1.h"

struct SBT_ITEM {
	int value;
	int size;
	struct SBT_ITEM *left, *right;
};

struct BST_SBT {
	struct SBT_ITEM *root;
};

struct SBT_ITEM *new_item(int value) {
	struct SBT_ITEM *p = malloc(sizeof(struct SBT_ITEM));
	p->value = value;
	p->size = 1;
	p->left = p->right = NULL;
	return p;
}

/* Size must be changed during rotation */
struct SBT_ITEM *sbt_left_rotate(struct SBT_ITEM *n) {
	struct SBT_ITEM *t = n->right;
	int size = 0;
	n->right = t->left;
	t->left = n;
	size = t->right?t->right->size:0;
	n->size -= (1 + size);
	size = n->left?n->left->size:0;
	t->size += (1 + size);
	return t;
}

/* Size must be changed during rotation */
struct SBT_ITEM *sbt_right_rotate(struct SBT_ITEM *n) {
	struct SBT_ITEM *t = n->left;
	int size = 0;
	n->left = t->right;
	t->right = n;
	size = t->left?t->left->size:0;
	n->size -= (1 + size);
	size = n->right?n->right->size:0;
	t->size += (1 + size);
	return t;
}

/* 
 * flag = 
 * 0: left subtree is inserted, might be bigger than right subtree;
 * 1: right subtree is inserted, might be bigger than left subtree.
 */
int maintain(struct SBT_ITEM **n, int flag) {
	if (!(*n))
		return 1;
	if (!(*n)->left || !(*n)->right)
		return 0;
	if (!flag)/*left*/ {
		if ((*n)->left->left && ((*n)->left->left->size > (*n)->right->size)) {
			*n = sbt_right_rotate(*n);
		}
		else if ((*n)->left->right && ((*n)->left->right->size > (*n)->right->size)) {
			(*n)->left = sbt_left_rotate((*n)->left);
			*n = sbt_right_rotate(*n);
		} else return 0;
	} else/*right*/ {
		if ((*n)->right->right && ((*n)->right->right->size > (*n)->left->size)) {
			*n = sbt_left_rotate(*n);
		}
		else if ((*n)->right->left && ((*n)->right->left->size > (*n)->left->size)) {
			(*n)->right = sbt_right_rotate((*n)->right);
			*n = sbt_left_rotate(*n);
		} else return 0;
	}
	maintain(&(*n)->left, 0);
	maintain(&(*n)->left, 1);
	maintain(&(*n)->right, 0);
	maintain(&(*n)->right, 1);
	maintain(&(*n), 1);
	maintain(&(*n), 0);
	return 0;
}

int size_maintain(int value, struct BST_SBT *r) {
	struct SBT_ITEM *p = NULL;
	if (!r || !r->root)
		return 1;
	p = r->root;
	while (1) {
		if (p->value == value) {
			return 0;
		}
		else if (p->value > value) {
			p->size--;
			p = p->left;
		} else {
			p->size--;
			p = p->right;
		}
	}
	return 1;
}

int insert__(int value, struct BST_SBT *r) {
	struct SBT_ITEM *p = NULL;
	if (!r)
		return 1;
	if (!r->root) {
		r->root = new_item(value);
		return 0;
	}
	p = r->root;
	while (1) {
		if (p->value == value) {
			return 1;
		}
		else if (p->value > value) {
			p->size++;
			if (!p->left) {
				p = p->left = new_item(value);
				maintain(&r->root, value > r->root->value);
				return 0;
			} else {
				p = p->left;
			}
		} else {
			p->size++;
			if (!p->right) {
				p = p->right = new_item(value);
				maintain(&r->root, value > r->root->value);
				return 0;
			} else {
				p = p->right;
			}
		}
	}
	return 1;
}

int insert(int value, struct BST_SBT *r) {
	int ret = insert__(value, r);
	if (ret)
		ret = size_maintain(value, r);
	return ret;
}

int search(int value, struct BST_SBT *r) {
	struct SBT_ITEM *p;
	if (!r || !r->root)
		return 1;
	p = r->root;
	while (p) {
		if (p->value == value) {
			return 0;
		} else if (p->value > value) {
			p = p->left;
		} else {
			p = p->right;
		}
	}
	return 1;
}

struct SBT_ITEM *sbt_select(struct SBT_ITEM *n, int idx) {
	int size;
	struct SBT_ITEM *ret;
	if (!n || n->size < idx || idx == 0)
		return NULL;
	if (!n->left)
		size = 0;
	else size = n->left->size;

	if (size >= idx) {
		ret = sbt_select(n->left, idx);
	} else if (size + 1 == idx) {
		ret = n;
	} else {
		ret = sbt_select(n->right, idx - size - 1);
	}
	return ret;
}

struct SBT_ITEM *sbt_get_item_by_order(struct BST_SBT *r, int idx) {
	return sbt_select(r->root, idx);
}

int bst_preorder(struct SBT_ITEM *n) {
	if (!n)
		return 0;
	fprintf(stdout, "%d ", n->value);
	bst_preorder(n->left);
	bst_preorder(n->right);
	return 0;
}

int main(int argc, char *argv[])
{
	int i = 0;
	int v = 0;
	struct BST_SBT *root = malloc(sizeof(struct BST_SBT));

	if (argc > 1) {
		if (!strncmp(argv[1], "-h", 2)) {
			fprintf(stdout,"Usage:\
./bst.out [N]\n");
			return -1;
		} else if (!strncmp(argv[1], "--help", 6)) {
			fprintf(stdout,"Usage:\
./bst.out [N]\n");
			return -1;
		}
		else {
			v = atoi(argv[1]);
		}
	}
	else {
		v = 205;
	}

	for (; i < SIZE; i++) {
		insert(a[i], root);
	}
	//bst_preorder(root->root);
	if (!search(v, root))
		fprintf(stdout, "The value %d exists.\n", v);
	else fprintf(stdout, "The value %d does not exist.\n", v);
	return 0;
}
