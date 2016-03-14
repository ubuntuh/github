#include <cstdio>

int main(void)
{
	int x, y;
	scanf("%d%d", &x, &y);
	if (x < y)
		puts("Better");
	else
		puts("Worse");
	return 0;
}
