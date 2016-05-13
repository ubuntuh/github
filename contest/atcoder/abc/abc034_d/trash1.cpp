#include <cstdio>

int N, K, w[1001], p[1001];

bool isAvailable(double density)
{
	int numHigher = 0;
	int higherWeight = 0;
	double higherSalt = 0;
	for (int i = 1; i <= N; ++i) {
		if (p >= density) {
			++numHigher;
			higherWeight += w[i];
			higherSalt += w[i] * p[i] / 100.;
		}
	}
	if (numHigher >= K)
		return true;
	int numLower = K - numHigher;
}

int main(void)
{
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &w[i], &p[i]);
	}
	return 0;
}
