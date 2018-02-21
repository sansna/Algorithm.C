/* Print Nth prime */
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int min_2(int m, int n);
int abs(int a);
int euc_mod(int m , int n);

int prime_test(int n);
int prime(int n);

int main()
{
	int n = 0;
	int64_t ret = 0;
	fprintf(stdout, "Please insert an int:\n");
	fscanf(stdin, " %d", &n);
	if (0 == n) {
		while (1) {
			n ++;
			ret = prime(n);
			fprintf(stdout, "%dth prime number is %d\n.", n, ret);
		}
	}
	ret = prime(n);
	fprintf(stdout, "%dth prime number is %d\n.", n, ret);
	
	return 0;
}

int prime(int n) {
	int i = 0;
	int m = 0;
	while (1) {
		m ++;
		if (prime_test(m)) {
			i ++;
			if ( i == n )
				break;
		}
	}
	return m;
}

int prime_test(int n) {
	int i = sqrt(n);
	for (; i > 1; i--) {
		if (1 == euc_mod(i, n))
			continue;
		else return 0;
	}
	return 1;
}

int min_2(int m, int n) {
	return (m < n)?m:n;
}

int abs(int a) {
	return (a < 0)?-a:a;
}

int euc_mod(int m , int n) {
	if (m == 0 || n == 0)
		return 0;
	if (m == n)
		return m;

	euc_mod(min_2(m,n), abs(m-n));
}
