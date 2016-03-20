// Wrong Answer.
// 部分点 30 点。C028_scrambled まで Accepted。
#include <climits>
#include <cstdio>

int N;	// [2, 1000]
int x[1001], y[1001], c[1001];

int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d%d%d", &x[i], &y[i], &c[i]);
	int xMin, xMax, yMin, yMax;
	xMin = yMin = INT_MAX;
	xMax = yMax = INT_MIN;
	for (int i = 1; i <= N; ++i) {
		if (x[i] < xMin)
			xMin = x[i];
		if (xMax < x[i])
			xMax = x[i];
		if (y[i] < yMin)
			yMin = y[i];
		if (yMax < y[i])
			yMax = y[i];
	}
	double xCenter = (xMax - xMin) / 2 + xMin;
	double yCenter = (yMax - yMin) / 2 + yMin;
	double answer;
	if (xCenter - xMin >= yCenter - yMin) {
		answer = xCenter - xMin;
	} else {
		answer = yCenter - yMin;
	}
	printf("%f\n", answer);
	return 0;
}
