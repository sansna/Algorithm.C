#include <stdio.h>

#define SIZE 100
int a[SIZE] = {843,44,727,774,90,270,243,957,135,473,949,462,813,531,320,812,195,208,132,371,837,898,835,28,319,1,191,556,947,369,247,677,408,691,583,228,511,314,108,816,805,735,768,278,442,287,218,944,749,824,651,676,680,485,676,861,405,23,291,811,920,185,550,734,162,720,783,57,803,13,817,506,990,906,832,744,97,175,717,211,808,445,979,895,648,39,340,122,54,943,443,985,273,591,37,65,470,959,6,75};

int sort_cmp(int a, int b);
int sort_quick_partition(int *a, int low, int high);
int sort_quick__(int *a, int low, int high);
int sort_quick(int *a, int size);

int main()
{
	int i;
	sort_quick(a, SIZE);

	for (i = 0; i < SIZE; i ++)
		fprintf(stdout, "%d,", a[i]);
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
