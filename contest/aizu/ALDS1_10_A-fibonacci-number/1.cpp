// Time Limit Exceeded.
// test case #10 以外で Accepted。
#include <cstdio>
#define NDEBUG

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
	if (termNum == 0)
		return 1;
	if (termNum == 1)
		return 1;
	return getFib(termNum - 1, depth + 1) + getFib(termNum - 2, depth + 1);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", getFib(n, 0));
	return 0;
}
