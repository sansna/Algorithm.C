#include <stdio.h>
//malloc
#include <stdlib.h>
//strncpy
#include <string.h>

#include "../random_set1.h"

struct SPLAY_ITEM {
	int value;
	struct SPLAY_ITEM *left, *right;
};

struct BST_SPLAY {
	struct SPLAY_ITEM *root;
};

struct SPLAY_ITEM *splay_right_rotate(struct SPLAY_ITEM *n) {
	struct SPLAY_ITEM *t = n->left;
	n->left = t->right;
	t->right = n;
	return t;
}

struct SPLAY_ITEM *splay_left_rotate(struct SPLAY_ITEM *n) {
	struct SPLAY_ITEM *t = n->right;
	n->right = t->left;
	t->left = n;
	return t;
}

struct SPLAY_ITEM *new_item(int value) {
	struct SPLAY_ITEM *p = malloc(sizeof(struct SPLAY_ITEM));
	p->value = value;
	p->left = p->right = NULL;
	return p;
}

/* Input root r should be malloced */
int insert(int value, struct BST_SPLAY *r) {
	struct SPLAY_ITEM *p;
	if (!r)
		return 1;
	if (!r->root) {
		r->root = malloc(sizeof(struct SPLAY_ITEM));
		r->root->value = value;
		return 0;
	}

	p = r->root;
	while (1) {
		if (value == p->value) {
			return 1;
		} else if (value < p->value) {
			if (!p->left) {
				p = p->left = new_item(value);
				return 0;
			}
			else p = p->left;
		} else {
			if (!p->right) {
				p = p->right = new_item(value);
				return 0;
			}
			else p = p->right;
		}
	}
}

int splaying(int value, struct SPLAY_ITEM **n) {
	int ret = 0;
	if (value == (*n)->value) {
		return 0;
	} else if (value < (*n)->value)/*left*/ {
		if (!(*n)->left)
			return 1;

		if (value == (*n)->left->value) {
			*n = splay_right_rotate(*n);
			return 0;
		} else if (value < (*n)->left->value)/*zig zig*/ {
			if (!(*n)->left->left)
				return 1;

			ret = splaying(value, &(*n)->left->left);
			*n = splay_right_rotate(*n);
			*n = splay_right_rotate(*n);
		} else/*zig zag*/ {
			if (!(*n)->left->right)
				return 1;

			ret = splaying(value, &(*n)->left->right);
			(*n)->left = splay_left_rotate((*n)->left);
			(*n) = splay_right_rotate(*n);
		}
	} else/*right*/ {
		if (!(*n)->right)
			return 1;

		if (value == (*n)->right->value) {
			*n = splay_left_rotate(*n);
			return 0;
		} else if (value > (*n)->right->value)/*zag zag*/ {
			if (!(*n)->right->right)
				return 1;

			ret = splaying(value, &(*n)->right->right);
			*n = splay_left_rotate(*n);
			*n = splay_left_rotate(*n);
		} else/*zig zag*/ {
			if (!(*n)->right->left)
				return 1;

			ret = splaying(value, &(*n)->right->left);
			(*n)->right = splay_right_rotate((*n)->right);
			*n = splay_left_rotate(*n);
		}
	}
	return ret;
}

/* Including Splaying */
int search(int value, struct BST_SPLAY *r) {
	if (!r || !r->root)
		return 1;

	return splaying(value, &(r->root));
}

int bst_midorder(struct SPLAY_ITEM *n) {
	if (!n)
		return 0;
	bst_midorder(n->left);
	fprintf(stdout, "%d ", n->value);
	bst_midorder(n->right);
	return 0;
}

int bst_preorder(struct SPLAY_ITEM *n) {
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
	struct BST_SPLAY *root = malloc(sizeof(struct BST_SPLAY));

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
		insert(a[i],root);
	}

	//bst_preorder(root->root);
	if (!search(v, root))
		fprintf(stdout, "The value %d exists.\n", v);
	else fprintf(stdout, "The value %d does not exist.\n", v);
	//bst_preorder(root->root);
	return 0;
}
