#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifdef RAND_MAX
#undef RAND_MAX
#endif
#define RAND_MAX 1000

int main()
{
	int n = 0;
	int tmp = 0;
	int rand_max = RAND_MAX;
	int ret = 0;
	FILE *pf1, *pf2 = NULL;

	fprintf(stdout, "Please insert # of rands:\n");
	fscanf(stdin, " %d", &n);
	rand_max = n*10>RAND_MAX?n*10:rand_max;

	pf1 = fopen("./random_set1.h","w");
	if (pf1 == NULL) {
		perror("Cannot open random_set1.h.\n");
		exit(1);
	}
	pf2 = fopen("./random_set2.h","w");
	if (pf1 == NULL) {
		perror("Cannot open random_set2.h.\n");
		exit(1);
	}

	fprintf(pf1, "#define SIZE %d\n", n);
	fprintf(pf2, "#define SIZE %d\n", n);
	
	fprintf(pf1, "int a[SIZE] = {", n);
	fprintf(pf2, "int a[SIZE + 1] = {", n);

	srand(time(NULL));
	for (; n > 1; n --) {
		tmp = rand()%rand_max;
		fprintf(pf1,"%d,", tmp);
		fprintf(pf2,"%d,", tmp);
		srand(rand());
	}
	tmp = rand()%rand_max;
	fprintf(pf1,"%d};", tmp);
	fprintf(pf2,"%d};", tmp);

	fflush(pf1);
	fflush(pf2);

	fclose(pf1);
	fclose(pf2);
	
	return 0;
}
