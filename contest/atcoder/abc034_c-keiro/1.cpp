// Runtime Error. 部分的 50 点。
// Runtime Error または Accepted. C002_scrambled、C027からC038、C051以降で RE。
// おそらく、大きな問題について RE が出ており、小さな問題については AC が出ている。大きな問題については、変数 denominator の値が 0 になり、0 除算エラーで RE である場合が多いだろう。
#include <cstdio>

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
	for (int i = 1; i <= W; ++i) {
		denominator *= i;
	}
	long numerator = 1;
	int max = W + H;
	for (int i = H + 1; i <= max; ++i) {
		numerator *= i;
	}
	// printf("numerator, denominator = %ld, %ld\n", numerator, denominator);
	long answer;
	answer = numerator / denominator;
	printf("%ld\n", answer);
	return 0;
}
