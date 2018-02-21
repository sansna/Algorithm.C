#include <stdio.h>

#define SIZE 100
#define LOOP (SIZE - 1)
int a[SIZE] = {843,44,727,774,90,270,243,957,135,473,949,462,813,531,320,812,195,208,132,371,837,898,835,28,319,1,191,556,947,369,247,677,408,691,583,228,511,314,108,816,805,735,768,278,442,287,218,944,749,824,651,676,680,485,676,861,405,23,291,811,920,185,550,734,162,720,783,57,803,13,817,506,990,906,832,744,97,175,717,211,808,445,979,895,648,39,340,122,54,943,443,985,273,591,37,65,470,959,6,75};

int swap_2(int *m, int *n);
int sort_cmp(int m, int n);
int sort_bubble_step(int *a, int i);
int sort_bubble(int *a, int size);

int main()
{
	int i;
	int ret = 0;
	ret = sort_bubble(a, SIZE);

	for (i = 0; i < 100; i ++)
		fprintf(stdout, "%d,", a[i]);
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
}

int sort_cmp(int m, int n) {
	return m<n?0:1;
}

int swap_2(int *m, int *n) {
	*m = *m ^ *n;
	*n = *m ^ *n;
	*m = *m ^ *n;
	return 0;
}
