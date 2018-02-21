#include <stdio.h>

#define SIZE 100
int a[SIZE + 1] = {0,843,44,727,774,90,270,243,957,135,473,949,462,813,531,320,812,195,208,132,371,837,898,835,28,319,1,191,556,947,369,247,677,408,691,583,228,511,314,108,816,805,735,768,278,442,287,218,944,749,824,651,676,680,485,676,861,405,23,291,811,920,185,550,734,162,720,783,57,803,13,817,506,990,906,832,744,97,175,717,211,808,445,979,895,648,39,340,122,54,943,443,985,273,591,37,65,470,959,6,75};

int sort_insert_step(int *a, int size, int i);
int sort_cmp(int a, int b);
int sort_insert(int *a, int size);

int main()
{
	int i;
	sort_insert(a, SIZE);

	for (i = 1; i <= SIZE; i ++)
		fprintf(stdout, "%d,", a[i]);
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
	return a<b?0:1;
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
