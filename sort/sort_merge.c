#include <stdio.h>

#define SIZE 100
int a[SIZE] = {843,44,727,774,90,270,243,957,135,473,949,462,813,531,320,812,195,208,132,371,837,898,835,28,319,1,191,556,947,369,247,677,408,691,583,228,511,314,108,816,805,735,768,278,442,287,218,944,749,824,651,676,680,485,676,861,405,23,291,811,920,185,550,734,162,720,783,57,803,13,817,506,990,906,832,744,97,175,717,211,808,445,979,895,648,39,340,122,54,943,443,985,273,591,37,65,470,959,6,75};
int b[SIZE];

int sort_cmp(int a, int b);
int sort_merge(int *a, int size);

int main()
{
	int i;
	sort_merge(a, SIZE);

	for (i = 0; i < SIZE; i ++) {
		fprintf(stdout, "%d,", a[i]);
	}
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
