#include <cstdio>
#include <cstdlib>

int fromPositive(int x)
{
	return x + 1000000000;
}

int fromNegative(int x)
{
	return x + 1000000001;
}

int normalize(int x)
{
	if (x > 0) return fromPositive(x);
	else return fromNegative(x);
}

int main()
{
	int A, B;
	scanf("%d%d", &A, &B);
	A = normalize(A);
	B = normalize(B);
	// printf("A, B = %d, %d\n", A, B);
	printf("%d\n", B - A);
	return 0;
}
