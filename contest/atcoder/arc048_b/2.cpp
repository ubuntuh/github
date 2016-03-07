// Time Limit Exceeded. 前回同様 24.txt まで TLE。
// わずかに計算量を減らした実装ですが、通るテストは増えませんでした。
#include <cstdio>

int N, R[100001], H[100001], win[100001], lose[100001], draw[100001];

bool isWin(int x, int y)
{
	--x;
	--y;
	return (y + 3 - x) % 3 == 1;
}

bool isLose(int x, int y)
{
	return isWin(y, x);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &R[i], &H[i]);
	}
	for (int i = 1; i <= N - 1; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			if (R[i] > R[j]) {
				++win[i];
				++lose[j];
			} else if (R[i] < R[j]) {
				++lose[i];
				++win[j];
			} else {
				if (isWin(H[i], H[j])) {
					++win[i];
					++lose[j];
				} else if (isLose(H[i], H[j])) {
					++lose[i];
					++win[j];
				} else {
					++draw[i];
					++draw[j];
				}
			}
		}
		printf("%d %d %d\n", win[i], lose[i], draw[i]);	
	}
	printf("%d %d %d\n", win[N], lose[N], draw[N]);
	return 0;
}
