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
	long answer = 1;
	int dn = 1;
	int max = W + H;
	for (int nm = H + 1; nm <= max; ++nm) {
		printf("nm, dn = %d, %d\n", nm, dn);
		answer *= nm;
		while (dn <= W && answer % dn == 0) {
			answer /= dn;
			printf("new ans = %ld\n", answer);
			++dn;
		}
		answer %= MOD_PRIME;
	}
	if (dn <= W) {
		printf("dn, W = %d, %d\n", dn, W);
	}
	printf("%ld\n", answer);
	return 0;
}
