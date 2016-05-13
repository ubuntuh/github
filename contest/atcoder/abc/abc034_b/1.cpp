#include <cstdio>

int main(void)
{
	int n;
	scanf("%d", &n);
	if (n % 2)
		printf("%d\n", n + 1);
	else
		printf("%d\n", n - 1);
	return 0;
}
