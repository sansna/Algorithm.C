#include <stdio.h>

#define SIZE 100
#define COLSIZE (SIZE + 1)
#define RADIX 10

#ifdef __GNUC__
#define unlikely(x) __builtin_expect(!!(x),0)
#else
#define unlikely(x) (x)
#endif

int a[SIZE] = {843,44,727,774,90,270,243,957,135,473,949,462,813,531,320,812,195,208,132,371,837,898,835,28,319,1,191,556,947,369,247,677,408,691,583,228,511,314,108,816,805,735,768,278,442,287,218,944,749,824,651,676,680,485,676,861,405,23,291,811,920,185,550,734,162,720,783,57,803,13,817,506,990,906,832,744,97,175,717,211,808,445,979,895,648,39,340,122,54,943,443,985,273,591,37,65,470,959,6,75};
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

int main()
{
	int i;
	sort_radix(a, RADIX);

	for (i = 0; i < SIZE; i ++) {
		fprintf(stdout, "%d,", a[i]);
	}
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
