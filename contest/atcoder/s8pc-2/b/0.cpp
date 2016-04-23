// [25, 32] で RE。
// 当然 AC とはならない素朴な実装。部分点 25 点を得た。
#include <cstdio>

long n;
long numbers[1000001];
int q;
int a;

int main(void)
{
	scanf("%ld%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		numbers[i] = i;
	}
	for (int i = 0; i < q; i++) {
		scanf("%d", &a);
		for (int j = 1; j <= n; j++) {
			if (numbers[j] % a == 0) {
				numbers[j] /= a;
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (numbers[i] == 1) {
			answer++;
		}
	}
	printf("%d\n", answer);
	return 0;
}
