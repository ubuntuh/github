// Accepted.
#include <cstdio>
#define NDEBUG

int fibs[45];

int getFib(int termNum, int depth)	// returns fibonacci number;
{
	static int numCall = 0;
	++numCall;
	for (int i = 0; i < depth; ++i) {
		#ifndef NDEBUG
		printf(" ");
		#endif
	}
	#ifndef NDEBUG
	printf("#%d getFib(%d, %d)\n", numCall, termNum, depth);
	#endif
	if (fibs[termNum] != -1)
		return fibs[termNum];
	if (termNum == 0)
		return 1;
	if (termNum == 1)
		return 1;
	fibs[termNum] =  getFib(termNum - 1, depth + 1) + getFib(termNum - 2, depth + 1);
	return fibs[termNum];
}

int main(void)
{
	for (int i = 0; i <= 44; ++i)
		fibs[i] = -1;
	int n;
	scanf("%d", &n);
	printf("%d\n", getFib(n, 0));
	return 0;
}
