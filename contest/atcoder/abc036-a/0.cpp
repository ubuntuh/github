// Accepted.
#include <cstdio>

int A;
int B;

int main(void)
{
	scanf("%d%d", &A, &B);
	int quotient = B / A;
	int answer;
	if (A * quotient == B) {
		answer = quotient;
	} else {
		answer = quotient + 1;
	}
	printf("%d\n", answer);
	return 0;
}
