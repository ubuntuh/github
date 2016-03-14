// Error.
#include <cstdio>

#define MOD_PRIME 1000000007
int W, H;

int main(void)
{
	scanf("%d%d", &W, &H);
	--W;
	--H;
	if (W > H) {
		int tmp = W;
		W = H;
		H = tmp;
	}
	long denominator = 1;
	int dnMod = 0, nmMod = 0;
	for (int i = 1; i <= W; ++i) {
		denominator *= i;
		if (denominator >= MOD_PRIME) {
			denominator %= MOD_PRIME;
			++dnMod;
		}
	}
	long numerator = 1;
	int max = W + H;
	for (int i = H + 1; i <= max; ++i) {
		numerator *= i;
		if (numerator >= MOD_PRIME) {
			numerator %= MOD_PRIME;
			++nmMod;
		}
	}
	printf("nmMod, dnMod = %d, %d\n", nmMod, dnMod);
	printf("numerator, denominator = %ld, %ld\n", numerator, denominator);
	long answer;
	answer = numerator / denominator;
	printf("%ld\n", answer);
	return 0;
}
