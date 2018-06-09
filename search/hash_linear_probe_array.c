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
	int (*insert)(int , struct SRH_HASH*);
	int (*search)(int, struct SRH_HASH*);
};

void tmp_init(struct SRH_HASH *ht) {
	int i = 0;
	ht->p = malloc(sizeof(struct HASH_ITEM*)*M);
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
	int bucket = ht->hash(value);
	while (ht->p[bucket]) {
		if (ht->p[bucket]->value == value)
			return 1;
		bucket++;
	}
	ht->p[bucket] = malloc(sizeof(struct HASH_ITEM));
	ht->p[bucket]->value = value;
	return 0;
}

/*
 * Return Value:
 * 0: Exists.
 * 1: Not exist.
 */
int tmp_search(int value, struct SRH_HASH *ht) {
	int bucket = ht->hash(value);
	while (ht->p[bucket]) {
		if (ht->p[bucket]->value == value)
			return 0;
		bucket++;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	struct SRH_HASH hash;
	int i = 0;
	int v = 0;

	hash.init = tmp_init;
	hash.hash = tmp_hash;
	hash.insert = tmp_insert;
	hash.search = tmp_search;

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
	return 0;
}
