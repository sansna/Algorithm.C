#include <stdio.h>

#include "../random_set2.h"

int sort_insert_step(int *a, int size, int i);
int sort_cmp(int a, int b);
int sort_insert(int *a, int size);

int main()
{
	int i;
	sort_insert(a, SIZE);

#ifndef __NO_PRINT
	for (i = 1; i < SIZE; i ++)
		fprintf(stdout, "%d,", a[i]);
#endif
	return 0;
}

int sort_insert(int *a, int size) {
	int i = 1;
	for (; i < size; i ++) {
		if (sort_cmp(a[i], a[i+1]))
			sort_insert_step(a, size, i);
	}
	return 0;
}

int sort_cmp(int a, int b) {
	return a<b?1:0;
}

int sort_insert_step(int *a, int size, int i) {
	int j = i;
	a[0] = a[i + 1];
	a[i + 1] = a[i];
	for (;sort_cmp(a[j - 1], a[0]); j --) {
		a[j] = a[j - 1];
	}
	a[j] = a[0];
	return 0;
}
