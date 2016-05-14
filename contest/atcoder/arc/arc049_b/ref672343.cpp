// reference = http://arc049.contest.atcoder.jp/submissions/672343
// Accepted.
#include <cstdio>
#include <cstdlib>

int N;	// [2, 1000]
int x[1001], y[1001], c[1001];

bool isAvailable(double t)	// 時間 t で全員到達できるか？
{
	for (int i = 1; i <= N - 1; ++i) {
		for (int j = i + 1; j <=N; ++j) {	// i 人目の高橋ノルム君と j 人目の高橋ノルム君について。
			int dy = abs(y[i] - y[j]);
			if (dy > t / c[i] + t / c[j])
				return false;
			int dx = abs(x[i] - x[j]);
			if (dx > t / c[i] + t / c[j])	// i 人目の高橋ノルム君は距離 t / c[i] しか j 人目の高橋ノルム君に近づけず、j 人目の高橋ノルム君は距離 t / c[j]　しか i 人目の高橋ノルム君に近づけない。二人の距離 dx がそれよりも大きい場合には、この二人が時間 t で出会えない。よって時間 t では全員到達できない。
				return false;
		}
		// i 人目の高橋ノルム君と j 人目の高橋ノルム君は時間 t で出会える。
	}
	return true;	// 全ての高橋ノルム君について時間 t で出会える。
}

void solve(void)
{
	double low = 0, high = 1000000000;
	for (int i = 1; i <= 64; ++i) {
		double mid = (low + high) / 2;
		if (isAvailable(mid))
			high = mid;
		else
			low = mid;
	}
	printf("%.10f\n", high);
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d%d%d", &x[i], &y[i], &c[i]);
	solve();
	return 0;
}
