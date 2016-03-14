// Accepted.
#include <cstdio>

long power(int base, int exponent, int prime)	// O(log(exponent));
{
	long result;
	if (exponent == 0)
		result = 1;
	else if (exponent % 2 == 0) {	// is even.
		long d = power(base, exponent / 2, prime);
		result = d * d % prime;
	} else {	// is odd.
		result =  base * power(base, exponent - 1, prime) % prime;
	}
	// printf("base, exponent, prime = %d, %d, %d\n", base, exponent, prime);
	// printf("\tresult = %ld\n", result);
	return result;
}

long combination(int n, int k, int prime)
{
	// printf("n, k = %d, %d\n", n, k);
	long numerator = 1;
	for (int i = n; i >= n - k + 1; --i) {
		numerator *= i;
		numerator %= prime;
	}
	long denominator = 1;
	for (int i = k; i >= 1; --i) {
		denominator *= power(i, prime - 2, prime);	// using Fermat's little theorem, that a^-1 is a^p-2 mod p.
		denominator %= prime;
	}
	// printf("numerator, denominator = %ld, %ld\n", numerator, denominator);
	return (numerator * denominator) % prime;
}

int main(void)
{
	int W, H;
	scanf("%d%d", &W, &H);
	printf("%ld\n", combination(W + H - 2, H - 1, 1000000007));
	return 0;
}
