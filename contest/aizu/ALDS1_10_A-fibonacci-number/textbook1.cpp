// Accepted.
#include <cstdio>

int dp[50];	// dp[45] と宣言してもいい。
int fib(int n)
{
	if (n == 0 || n == 1)
		return dp[n] = 1;	// しかし dp[0] または dp[1] が読み込まれることはない。
	if (dp[n] != -1)	// cache のチェックを冒頭で行わないのは不可解である。
		return dp[n];
	return dp[n] = fib(n - 1) + fib(n - 2);
}

int main(void)
{
	int n, i;
	for (i = 0; i < 50; ++i)	// 複数箇所への定数の埋め込み。
		dp[i] = -1;	// 初期値。しかし global variable の初期値 0 を不定値として使うこともできる。
	scanf("%d", &n);
	printf("%d\n", fib(n));
	return 0;
}
