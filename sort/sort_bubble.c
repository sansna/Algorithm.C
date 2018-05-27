#include <stdio.h>

#include "../random_set1.h"
#define LOOP (SIZE - 1)

int swap_2(int *m, int *n);
int sort_cmp(int m, int n);
int sort_bubble_step(int *a, int i);
int sort_bubble(int *a, int size);

int main()
{
	int i;
	int ret = 0;
	ret = sort_bubble(a, SIZE);
#ifndef __NO_PRINT
	for (i = 0; i < SIZE; i ++)
		fprintf(stdout, "%d,", a[i]);
#endif
	return 0;
}

int sort_bubble(int *a, int size) {
	int i = 0;
	for (; i < LOOP; i ++) {
		sort_bubble_step(a, i);
	}
	return 0;
}

int sort_bubble_step(int *a, int i) {
	int j = 0;
	for (; j < SIZE - i - 1; j ++) {
		if (sort_cmp(a[j], a[j + 1]))
			swap_2(&a[j], &a[j + 1]);
	}
	return 0;
}

int sort_cmp(int m, int n) {
	return m<n?1:0;
}

int swap_2(int *m, int *n) {
	*m = *m ^ *n;
	*n = *m ^ *n;
	*m = *m ^ *n;
	return 0;
}
