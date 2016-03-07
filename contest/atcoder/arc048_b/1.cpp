// Time Limit Exceeded. 少数で Accepted、残り大多数のテストで TLE でした。具体的には、24.txt まで TLE。
// 素朴な総当り法 (brute force method) による実装です。
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
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == j)
				continue;
			if (R[i] > R[j]) {
				++win[i];
			} else if (R[i] < R[j]) {
				++lose[i];
			} else {
				if (isWin(H[i], H[j])) {
					++win[i];
				} else if (isLose(H[i], H[j])) {
					++lose[i];
				} else {
					++draw[i];
				}
			}
		}
		printf("%d %d %d\n", win[i], lose[i], draw[i]);
	}
	return 0;
}
