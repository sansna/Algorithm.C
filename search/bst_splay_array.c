#include <stdio.h>
//atoi
#include <stdlib.h>
//strncpy
#include <string.h>

#include "../random_set1.h"

struct SPLAY_ITEM {
	int value, son[2];
} tree[SIZE];
int cur = 0;
int root = 0;

int new_node(int value) {
	if (cur >= SIZE - 1)
		return 1; 
	tree[cur].value = value;
	tree[cur].son[0] = SIZE;
	tree[cur].son[1] = SIZE;
	return cur++;
}

/*
 * flag:
 * 0: right rotate;
 * 1: left rotate.
 */
int splay_rotate(int n, int flag) {
	int t = tree[n].son[flag];
	tree[n].son[flag] = tree[t].son[!flag];
	tree[t].son[!flag] = n;
	return t;
}

int splay_insert(int value) {
	int n = 0;
	while (n < cur) {
		if (tree[n].value == value) {
			return 1;
		} else if (tree[n].son[tree[n].value < value] != SIZE) {
			n = tree[n].son[tree[n].value < value];
		} else {
			tree[n].son[tree[n].value < value] = new_node(value);
			return 0;
		}
	}
	new_node(value);
	return 0;
}

int splaying(int value, int *n) {
	int t0 = tree[*n].value < value;
	int t1;
	int t;
	int ret = 0;
	if (tree[*n].value == value) {
		return 0;
	} else/*left right*/ {
		if (tree[*n].son[t0] >= cur)
			return 1;

		t1 = tree[tree[*n].son[t0]].value < value;
		t = t1==t0;

		if (tree[tree[*n].son[t0]].value == value) {
			*n = splay_rotate(*n, t0);
			return 0;
		}
		if (tree[tree[*n].son[t0]].son[t1] >= cur)
			return 1;
		if (t)/*zigzig or zagzag*/ {
			ret = splaying(value, &tree[tree[*n].son[t0]].son[t1]);
			*n = splay_rotate(*n, t0);
			*n = splay_rotate(*n, t0);
		} else/*zig zag*/ {
			ret = splaying(value, &tree[tree[*n].son[t0]].son[t1]);
			tree[*n].son[t0] = splay_rotate(tree[*n].son[t0], t1);
			*n = splay_rotate(*n, t0);
		}
	}
	return ret;
}

int splay_search(int value) {
	if (!cur)
		return 1;
	return splaying(value, &root);
}

int main(int argc, char *argv[])
{
	int i = 0;
	int v = 0;

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
		splay_insert(a[i]);
	}
	if (!splay_search(v))
		fprintf(stdout, "The value %d exists.\n", v);
	else fprintf(stdout, "The value %d does not exist.\n", v);
	return 0;
}
