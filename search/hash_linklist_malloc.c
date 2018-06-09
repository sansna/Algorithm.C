#include <stdio.h>

//malloc/atoi
#include <stdlib.h>
//strncmp
#include <string.h>
//int a[SIZE]
#include "../random_set1.h"

#define BUCKETS SIZE
struct HASH_LINK_LST {
	int value;
	struct HASH_LINK_LST *next;
};
struct SRH_HASH {
	struct HASH_LINK_LST *p[BUCKETS];
	void (*init)(struct SRH_HASH *ht);
	int (*insert)(int value, struct SRH_HASH *ht);
	int (*search)(int value, struct SRH_HASH *ht);
	int (*del)(int value, struct SRH_HASH *ht);
	int (*hash)(int value);
};

void tmp_init(struct SRH_HASH *ht) {
	int i = 0;
	for (;i < BUCKETS; i ++) {
		ht->p[i] = NULL;
	}
	return;
}

/* Main Hash function which impacts efficiency */
int tmp_hash(int v) {
	return v%BUCKETS;
}

/* Adding Link list item through malloc */
struct HASH_LINK_LST *tmp_add_lst() {
	return malloc(sizeof(struct HASH_LINK_LST));
}

int tmp_insert(int v, struct SRH_HASH *ht) {
	int bucket;
	struct HASH_LINK_LST *l, *new;
	bucket = ht->hash(v);
	l = ht->p[bucket];
	while (l) {
		if (l->value != v)
			l = l->next;
		else
			return 1;
	}
	if (!l) {
		l = tmp_add_lst();
		l->value = v;
		l->next = ht->p[bucket];
		ht->p[bucket] = l;
	}
	return 0;
}

int tmp_search(int v, struct SRH_HASH *ht) {
	int bucket;
	struct HASH_LINK_LST *l;
	
	bucket = ht->hash(v);
	l = ht->p[bucket];
	while (l) {
		if (l->value == v)
			return 0;
		l = l->next;
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
	hash.del = NULL;

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
