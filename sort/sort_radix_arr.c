#include <stdio.h>

#include "../random_set1.h"

#define COLSIZE (SIZE + 1)
#define RADIX 10
//Auxiliary storage.
int b[RADIX * COLSIZE] = {0};

int sort_radix(int *a, int size);

int main()
{
	int i;
	sort_radix(a, RADIX);

#ifndef __NO_PRINT
	for (i = 0; i < SIZE; i ++)
		fprintf(stdout, "%d,", a[i]);
#endif
	return 0;
}

int sort_cardinal(int *a, int n) {
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
	while (sort_cardinal(a, (i *= RADIX)/RADIX));
	return 0;
}
