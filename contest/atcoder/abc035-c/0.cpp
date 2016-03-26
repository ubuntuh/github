// Accepted.
#include <cstdio>

int N, Q, flags[200000];

int main(void)
{
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < Q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		flags[l - 1] ^= 1;
		if (r != N)
			flags[r] ^= 1;
	}
	int isBlack = 1;
	for (int i = 0; i < N; ++i) {
		if (flags[i])
			isBlack = !isBlack;
		if (isBlack)
			printf("0");
		else
			printf("1");
	}
	puts("");
	return 0;
}
