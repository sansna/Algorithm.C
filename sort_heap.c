#include <stdio.h>

#define SIZE 100
int a[SIZE + 1] = {0,843,44,727,774,90,270,243,957,135,473,949,462,813,531,320,812,195,208,132,371,837,898,835,28,319,1,191,556,947,369,247,677,408,691,583,228,511,314,108,816,805,735,768,278,442,287,218,944,749,824,651,676,680,485,676,861,405,23,291,811,920,185,550,734,162,720,783,57,803,13,817,506,990,906,832,744,97,175,717,211,808,445,979,895,648,39,340,122,54,943,443,985,273,591,37,65,470,959,6,75};

int sort_cmp(int a, int b);
int sort_reheap(int *a, int size, int idx);
int sort_heap(int *a, int size);

int main()
{
	int i = 0;
	sort_heap(a, SIZE);

	for (i = 1; i <= 100; i ++)
		fprintf(stdout, "%d,", a[i]);
	return 0;
}

int sort_heap(int *a, int size) {
	int i = SIZE/2;
	int ret;
	for (; i > 0; i --) {
		sort_reheap(a, SIZE, i);
	}
	i = SIZE;
	for (; i > 1; i --) {
		ret = 1;
		a[i] = a[i] ^ a[1];
		a[1] = a[i] ^ a[1];
		a[i] = a[i] ^ a[1];

		ret = sort_reheap(a, i - 1, 1);
	}
	return 0;
}

int sort_reheap(int *a, int size, int idx) {
	int tmp = idx;
	if (idx * 2 <= size) {
		if (sort_cmp(a[2*idx], a[idx]))
			tmp = 2 * idx;
		if (((2*idx + 1) <= size) 
			&& sort_cmp(a[2*idx + 1], a[tmp]))
			tmp = 2 * idx + 1;

		if (tmp != idx) {
			a[idx] = a[idx] ^ a[tmp];
			a[tmp] = a[idx] ^ a[tmp];
			a[idx] = a[idx] ^ a[tmp];

			sort_reheap(a, size, tmp);
			return 0;
		}
		else
			return 0;
	}
	return 0;
}

int sort_cmp(int a, int b) {
	return a<b?0:1;
}
