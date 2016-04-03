// Accepted.
#include <cstdio>

char C, c;

int main(void)
{
	scanf(" %c %c", &C, &c);
	if (C + 0x20 == c)
		puts("Yes");
	else
		puts("No");
	return 0;
}
