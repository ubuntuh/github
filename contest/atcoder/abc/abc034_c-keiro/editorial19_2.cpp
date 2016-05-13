// Time Limit Exceeded。部分点100点。なお満点は101点である。
// 多くの入力について Accepted.
#include <cstdio>

long longs[100000];

int dp(int w, int h)	// dynamic programming.
{
	for (int x = 0; x < w; ++x) {
		longs[x] = 1;
	}
	for (int y = 1; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			long left = 0;
			if (x != 0)
				left = longs[x - 1];
			longs[x] = (left + longs[x]) % 1000000007;
			// printf(" %d", longs[x]);
		}
		// puts("");
	}
	return longs[w - 1];
}

int main(void)
{
	int W, H;
	scanf("%d%d", &W, &H);
	printf("%d\n", dp(W, H));
	return 0;
}
