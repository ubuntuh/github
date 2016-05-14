// Accepted. editorial に従った実装。
#include <cstdio>

int N;	// [2, 1000]
int x[1001], y[1001], c[1001];

bool isAvailable(double t)
{
	double xLeftMax, xRightMin, yLeftMax, yRightMin;
	xLeftMax = yLeftMax = -100000;
	xRightMin = yRightMin = 100000;	// 例えば最も遠い x = 100000 にいた高橋ノルム君が最も高速な c = 1 で、最も時間を与えられず時間 0 で移動したとしても、x = 100000 までは左に進む。
	for (int i = 1; i <= N; ++i) {
		double walked = t / c[i];
		double xLeft = x[i] - walked;
		double xRight = x[i] + walked;
		double yLeft = y[i] - walked;
		double yRight = y[i] + walked;
		if (xLeftMax < xLeft)
			xLeftMax = xLeft;
		if (xRight < xRightMin)
			xRightMin = xRight;
		if (yLeftMax < yLeft)
			yLeftMax = yLeft;
		if (yRight < yRightMin)
			yRightMin = yRight;
	}
	if (xRightMin < xLeftMax)
		return false;
	if (yRightMin < yLeftMax)
		return false;
	return true;
}

void solve(void)
{
	double low = 0, high = 100000 * 1000;	// 例えば 1 人目の高橋ノルム君の位置 x_1 = 100000 であって c_1 = 1000 であり、2 人目の高橋ノルム君の位置 x_2 = -100000 であって c_2 = 1000 である時、時間 100000 * 1000 かけて x = 0 で出会う。これが（かかる時間の）最大値である。
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
