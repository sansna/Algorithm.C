#include <stdio.h>
#include "./random_set1.h"

int swap(int *a, int m, int n) {
	if (a[m] == a[n])
		return 0;
	a[m] = a[m] ^ a[n];
	a[n] = a[m] ^ a[n];
	a[m] = a[m] ^ a[n];
	return 0;
}

int split(int *a, int size, int *ss, int *ls, int *sb, int *lb) {
	int t = a[0];
	int i = 1;
	int ret = 1;
	*ss = 1;
	*ls = 0;
	*sb = 1;
	*lb = 0;
	for (; i < size; i++) {
		if (a[i] == t) {
			if (lb > 0 && ls > 0) {
				swap(a, i, *sb);
				swap(a, (*sb), ret++);
			} else {
				swap(a, i, ret++);
			}
			(*ss)++;
			(*sb)++;
		} else if (a[i] < t) {
			swap(a, i, (*ss)+(*ls));
			(*ls)++;
			(*sb)++;
		} else {
			(*lb)++;
		}
	}
	return ret;
}

int get_by_order(int *a, int idx) {
	int ss = 0, ls = 0, sb = 0, lb = 0, se = 0;
	int size = SIZE;
	int ret = 0;
	int *b = a;
	if (idx > SIZE)
		return -1;
	while (1) {
		se = split(b, size, &ss, &ls, &sb, &lb);
		if (ls >= idx) {
			b += (se);
			size = ls;
		} else if (ls + se >= idx) {
			return b[0];
		} else {
			idx -= (ls+se);
			b += (ls+se);
			size = lb;
		}
	}
	return -1;
}

int main() {
	double ret = 0;
	int r1 = 0, r2 = 0;
	if (SIZE%2) {
		r1 = get_by_order(a, (SIZE+1)/2);
		ret = (double)r1;
	} else {
		r1 = get_by_order(a, SIZE/2);
		r2 = get_by_order(a, SIZE/2 + 1);
		ret = (double)(r1 + r2)/2.0;
	}
	fprintf(stdout, "Median of set a[%d] is %llf.\n", SIZE, ret);
	return 0;
}
