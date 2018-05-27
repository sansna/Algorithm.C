#include <stdio.h>

#include "../random_set1.h"

int b[SIZE];

int sort_cmp(int a, int b);
int sort_merge(int *a, int size);

int main()
{
	int i;
	sort_merge(a, SIZE);

#ifndef __NO_PRINT
	for (i = 0; i < SIZE; i ++)
		fprintf(stdout, "%d,", a[i]);
#endif
	return 0;
}

int sort_merge_step(int *a, int i0, int i1, int i2, int *b) {
	int s1 = i0, s2 = i1;
	int sb = i0;
	int j = 0;
	while (s1 < i1 && s2 < i2) {
		if (sort_cmp(a[s1], a[s2]))
			b[sb++] = a[s1++];
		else b[sb++] = a[s2++];
	}
	s1 = (s1==i1)?s2:s1;
	for (j = sb; j < i2; j ++) {
		b[sb++] = a[s1++];
	}
	return 0;
}

int sort_cmp(int a, int b) {
	return a<b?1:0;
}

int sort_mpass(int *a, int *b, int l, int size) {
	int i = 0;
	for (; i < size - 2*l; i += 2*l) {
		sort_merge_step(a, i, i + l, i + 2*l, b);
	}
	if (i+l < size) sort_merge_step(a, i, i + l, size, b);
	else for (; i < size; i ++) {
		b[i] = a[i];
	}
	return 0;
}

int sort_merge(int *a, int size) {
	int l = 1;
	for (; l < size; l *= 2) {
		sort_mpass(a, b, l, size);
		l *= 2;
		sort_mpass(b, a, l, size);
	}
	return 0;
}
