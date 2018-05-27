#include <stdio.h>

#include "../random_set1.h"

#define COLSIZE (SIZE + 1)
#define RADIX 10

#ifdef __GNUC__
#define unlikely(x) __builtin_expect(!!(x),0)
#else
#define unlikely(x) (x)
#endif

//Auxiliary storage.
struct SLINK_LIST {
	struct SLINK_LIST *next;
	int n;
} slnk_lst[SIZE] = {0};

struct SLINK_HEAD {
	struct SLINK_LIST *ptr;
	struct SLINK_LIST *tail;
} slnk_hdr[RADIX] = {0};
//Auxiliary storage.

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
	int i = 0, k = 0;
	int card;
	struct SLINK_LIST *ptr;
	for (; i < SIZE; i ++) {
		card = a[i]%(RADIX * n)/n;
		slnk_lst[i].n = a[i];
		if (unlikely(!slnk_hdr[card].ptr))
			slnk_hdr[card].ptr = &slnk_lst[i];
		else slnk_hdr[card].tail = slnk_hdr[card].tail->next = &slnk_lst[i];
		slnk_hdr[card].tail = &slnk_lst[i];
	}
	card = 0;
	for (i = 0; i < RADIX; i ++) {
		for (ptr = slnk_hdr[i].ptr; ptr != NULL; ptr = ptr->next)
			a[k++] = ptr->n;
		if (slnk_hdr[i].ptr != NULL)
			card ++;
		slnk_hdr[i].ptr = NULL;
	}
	if (card == 1)
		return 0;

	for (i = 0; i < SIZE; i ++)
		slnk_lst[i].next = NULL;
	return 1;
}

int sort_radix(int *a, int size) {
	int i = 1;
	while (sort_cardinal(a, (i *= RADIX)/RADIX));
	return 0;
}
