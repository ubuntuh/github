#include <cstdio>

int main(void)
{
	int W, H;
	scanf("%d%d", &W, &H);
	if (W * 3 / 4 == H)	// W * 3 の最大値は 300,000 である。
		puts("4:3");
	else
		puts("16:9");
	return 0;
}
