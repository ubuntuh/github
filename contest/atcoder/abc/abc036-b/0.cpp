// Accepted.
#include <cstdio>

int N;
char s[50][50];

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &s[i][j]);
		}
	}
	for (int j = 0; j < N; j++) {
		for (int i = N - 1; i >= 0; i--) {
			printf("%c", s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
