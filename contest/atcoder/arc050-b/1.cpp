#include <algorithm>
#include <cstdio>
using namespace std;

long R, B, x, y;

long numBouquet(long numX)
{
	long xMax = min(R / x, B);
	if (numX >= xMax)
		numX = xMax;
	long R1 = R - x * numX;
	long B1 = B - numX;
	long numY = min(R1, B1 / y);
	printf("numX, numY = %ld, %ld\n", numX, numY);
	return numX + numY;
}

int main(void)
{
	scanf("%ld%ld%ld%ld", &R, &B, &x, &y);
	long xMax = min(R / x, B);
	long yMax = min(R, B / y);
	for (long i = 0; i < 100; i++) {
		printf("%ld, %ld\n", i, numBouquet(i));
	}
	return 0;
}
