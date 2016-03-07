// Accepted.
#include <cstdio>
#include <cstdlib>

int main()
{
	int A, B, answer;
	scanf("%d%d", &A, &B);
	if (A < 0) {
		if (B < 0) {
			answer = abs(A) - abs(B);
		} else {
			answer = abs(A) + B - 1;
		}
	} else {
		answer = B - A;
	}
	printf("%d\n", answer);
	return 0;
}
