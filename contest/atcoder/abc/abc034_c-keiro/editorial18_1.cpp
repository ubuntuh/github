// Time Limit Exceeded。部分点 50。
// 一部の（小さな）入力について Accepted。
#include <cstdio>

int dfs(int w, int h)	// depth-first search.
{
	if (w == -1 || h == -1)	// out of the field.
		return 0;
	if (w == 0 && h == 0)	// one of the goals.
		return 1;
	// printf("dfs(%d, %d);\n", w, h);
	return dfs(w, h - 1) + dfs(w - 1, h);
}

int main(void)
{
	int W, H;
	scanf("%d%d", &W, &H);
	--W;
	--H;
	printf("%d\n", dfs(W, H));
	return 0;
}
