#include <stdio.h>

#include "../random_set1.h"

int sort_cmp(int a, int b);
int sort_quick_partition(int *a, int low, int high);
int sort_quick__(int *a, int low, int high);
int sort_quick(int *a, int size);

int main()
{
	int i;
	sort_quick(a, SIZE);

#ifndef __NO_PRINT
	for (i = 0; i < SIZE; i ++)
		fprintf(stdout, "%d,", a[i]);
#endif
	return 0;
}

int sort_quick__(int *a, int low, int high) {
	int piv_loc;
	if (low < high) {
		piv_loc = sort_quick_partition(a, low, high);
		sort_quick__(a, low, piv_loc - 1);
		sort_quick__(a, piv_loc + 1, high);
	}
	return 0;
}

int sort_quick_partition(int *a, int low, int high) {
	int pivot = a[low];
	while (low < high) {
		while (low < high && sort_cmp(pivot, a[high])) high --;
		a[low] = a[high];
		while (low < high && sort_cmp(a[low], pivot)) low ++;
		a[high] = a[low];
	}
	a[low] = pivot;
	return low;
}

int sort_quick(int *a, int size) {
	sort_quick__(a, 0, size - 1);
	return 0;
}

int sort_cmp(int a, int b) {
	return a<=b?1:0;
}
