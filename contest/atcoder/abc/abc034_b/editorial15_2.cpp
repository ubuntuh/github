#include <cstdio>

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (n - 1 ^ 1) + 1);	// xor による交換。
}
