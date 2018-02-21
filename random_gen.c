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
	int ret = 0;
	fprintf(stdout, "Please insert # of rands:\n");
	fscanf(stdin, " %d", &n);
	srand(time(NULL));
	for (; n > 1; n --) {
		fprintf(stdout,"%d,", rand()%RAND_MAX);
		srand(rand());
	}
	fprintf(stdout,"%d\n", rand()%RAND_MAX);
	
	return 0;
}
