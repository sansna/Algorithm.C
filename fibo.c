/* Fibonacci */
#include <stdio.h>

int fibo(int n);

int main()
{
	int n = 0;
	int ret = 0;
	fprintf(stdout, "Please input N:\n");
	fscanf(stdin, " %d", &n);
	ret = fibo(n);
	fprintf(stdout, "Result of fibo(n) = %d\n", ret);

	return 0;
}

int fibo(int n){
	if (n < 0)
		return -1;

	switch (n){
		case 0:
			return 0;
			break;
		case 1:
			return 1;
			break;
		default:
			return fibo(n - 1) + fibo(n - 2);
	}
}
