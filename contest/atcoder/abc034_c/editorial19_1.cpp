#include <cstdio>

int ints[100000];

int dp(int w, int h)	// dynamic programming.
{
	for (int x = 0; x < w; ++x) {
		ints[x] = 1;
	}
	for (int y = 1; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			int left = 0;
			if (x != 0)
				left = ints[x - 1];
			ints[x] = left + ints[x];
			// printf(" %d", ints[x]);
		}
		// puts("");
	}
	return ints[w - 1];
}

int main(void)
{
	int W, H;
	scanf("%d%d", &W, &H);
	printf("%d\n", dp(W, H));
	return 0;
}
