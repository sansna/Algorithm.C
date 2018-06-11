/* If multiple elements are of same value, elements are ignored. */
#include <stdio.h>
//malloc
#include <stdlib.h>
//strncmp
#include <string.h>

#include "../random_set1.h"

#define ALPHA 2
#define N SIZE
#define M (SIZE * ALPHA)
struct HASH_ITEM {
	int value;
};
struct SRH_HASH {
	struct HASH_ITEM **p;
	void (*init)(struct SRH_HASH*);
	int (*hash)(int);
	struct HASH_ITEM **(*add_items)(void);
	struct HASH_ITEM *(*add)(void);
	int (*insert)(int , struct SRH_HASH*);
	int (*search)(int, struct SRH_HASH*);
	void (*free)(struct SRH_HASH*);
};

struct HASH_ITEM **tmp_init_items() {
	return malloc(sizeof(struct HASH_ITEM*)*M);
}

struct HASH_ITEM *tmp_add_item() {
	return malloc(sizeof(struct HASH_ITEM));
}

void tmp_init(struct SRH_HASH *ht) {
	int i = 0;
	ht->p = ht->add_items();
	for (;i < M; i ++) {
		ht->p[i] = NULL;
	}
	return;
}

int tmp_hash(int value) {
	return value%N;
}

/*
 * Return Value:
 * 0: Duplicated insert, ignored.
 * 1: Successfully inserted.
 */
int tmp_insert(int value, struct SRH_HASH *ht) {
	int bucket = ht->hash(value)*ALPHA;
	while (ht->p[bucket]) {
		if (ht->p[bucket]->value == value)
			return 1;
		bucket++;
	}
	ht->p[bucket] = ht->add();
	ht->p[bucket]->value = value;
	return 0;
}

/*
 * Return Value:
 * 0: Exists.
 * 1: Not exist.
 */
int tmp_search(int value, struct SRH_HASH *ht) {
	int bucket = ht->hash(value)*ALPHA;
	while (ht->p[bucket]) {
		if (ht->p[bucket]->value == value)
			return 0;
		bucket++;
	}
	return 1;
}

void tmp_free(struct SRH_HASH* ht) {
	int i = 0;
	for (; i < M; i++) {
		if (ht->p[i])
			free(ht->p[i]);
	}
	free(ht->p);
	return;
}

int main(int argc, char *argv[])
{
	struct SRH_HASH hash;
	int i = 0;
	int v = 0;

	hash.init = tmp_init;
	hash.hash = tmp_hash;
	hash.add_items = tmp_init_items;
	hash.add = tmp_add_item;
	hash.insert = tmp_insert;
	hash.search = tmp_search;
	hash.free = tmp_free;

	if (argc > 1) {
		if (!strncmp(argv[1], "-h", 2)) {
			fprintf(stdout,"Usage:\
./hash.out [N]\n");
			return -1;
		} else if (!strncmp(argv[1], "--help", 6)) {
			fprintf(stdout,"Usage:\
./hash.out [N]\n");
			return -1;
		}
		else {
			v = atoi(argv[1]);
		}
	}
	else {
		v = 205;
	}

	hash.init(&hash);
	for (; i < SIZE; i++) {
		hash.insert(a[i], &hash);
	}

	if (!hash.search(v, &hash))
		fprintf(stdout, "The value %d exists.\n", v);
	else fprintf(stdout, "The value %d does not exist.\n", v);

	hash.free(&hash);
	return 0;
}
