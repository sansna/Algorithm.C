#include <stdio.h>

#define SIZE 100
#define COLSIZE (SIZE + 1)
#define RADIX 10
int a[SIZE] = {843,44,727,774,90,270,243,957,135,473,949,462,813,531,320,812,195,208,132,371,837,898,835,28,319,1,191,556,947,369,247,677,408,691,583,228,511,314,108,816,805,735,768,278,442,287,218,944,749,824,651,676,680,485,676,861,405,23,291,811,920,185,550,734,162,720,783,57,803,13,817,506,990,906,832,744,97,175,717,211,808,445,979,895,648,39,340,122,54,943,443,985,273,591,37,65,470,959,6,75};
//Auxiliary storage.
int b[RADIX * COLSIZE] = {0};

int main()
{
	int i;
	sort_radix(a, RADIX);

	for (i = 0; i < SIZE; i ++) {
		fprintf(stdout, "%d,", a[i]);
	}
	return 0;
}

int sort_cardinal(int *a, int *b, int n) {
	int i = 0, j = 0, k = 0;
	int card;
	for (; i < SIZE; i ++) {
		card = a[i]%(RADIX * n)/n;
		//b[card][++b[card][0]] = a[i];
		b[card*COLSIZE + (++b[card*COLSIZE])] = a[i];
	}
	card = 0;
	for (i = 0; i < RADIX; i ++) {
		for (j = 1; j <= b[i * COLSIZE]; j ++) {
			a[k++] = b[i*COLSIZE + j];
		}
		b[i * COLSIZE] = 0;
		if (j != 1)
			card ++;
	}
	if (card == 1)
		return 0;
	return 1;
}

int sort_radix(int *a, int size) {
	int i = 1;
	while (sort_cardinal(a, b, (i *= RADIX)/RADIX));
	return 0;
}
