/* Euclid-Modular algo */
#include <stdio.h>

int min_2(int m, int n);
int abs(int a);
int euc_mod(int m, int n);

int main()
{
	int m = 0,n = 0;
	int ret = 0;
	fprintf(stdout, "Please insert 2 int:\n");
	fscanf(stdin, " %d %d", &m, &n);
	ret = euc_mod(m, n);
	fprintf(stdout, "GCD of %d and %d is: %d\n", m, n, ret);
	
	return 0;
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
