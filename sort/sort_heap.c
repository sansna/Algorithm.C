#include <stdio.h>

#include "../random_set2.h"

int sort_cmp(int a, int b);
int sort_reheap(int *a, int size, int idx);
int sort_heap(int *a, int size);

int main()
{
	int i = 0;
	sort_heap(a, SIZE);

#ifndef __NO_PRINT
	for (i = 1; i < SIZE; i ++)
		fprintf(stdout, "%d,", a[i]);
#endif
	return 0;
}

int sort_heap(int *a, int size) {
	int i = SIZE/2;
	for (; i > 0; i --) {
		sort_reheap(a, SIZE, i);
	}
	i = SIZE;
	for (; i > 1; i --) {
		a[i] = a[i] ^ a[1];
		a[1] = a[i] ^ a[1];
		a[i] = a[i] ^ a[1];

		sort_reheap(a, i - 1, 1);
	}
	return 0;
}

int sort_reheap(int *a, int size, int idx) {
	int rc = a[idx];
	int j;
	for (j = 2 * idx; j <= size; j *= 2) {
		if (j < size && (!sort_cmp(a[j], a[j + 1]))) j ++;
		if (sort_cmp(rc, a[j]))
			break;
		a[idx] = a[j];
		idx = j;
	}
	a[idx] = rc;
	return 0;
}

int sort_cmp(int a, int b) {
	return a<b?1:0;
}
