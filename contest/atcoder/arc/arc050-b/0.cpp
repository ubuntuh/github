#include <algorithm>
#include <cstdio>
using namespace std;

long R, B, x, y;

int main(void)
{
	scanf("%ld%ld%ld%ld", &R, &B, &x, &y);
	long xMax = min(R / x, B);
	long yMax = min(R, B / y);
	printf("R, B = %ld %ld\n", R, B);
	printf("xMax, yMax = %ld %ld\n", xMax, yMax);
	if (xMax >= yMax) {
		R -= x * xMax;
		B -= xMax;
		yMax = min(R, B / y);
	} else {
		R -= yMax;
		B -= y * yMax;
		xMax = min(R / x, B);
	}
	printf("R, B = %ld %ld\n", R, B);
	printf("xMax, yMax = %ld %ld\n", xMax, yMax);
	printf("%ld\n", xMax + yMax);
	return 0;
}
