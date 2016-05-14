#include <cstdio>

int main(void)
{
	char S[101];
	scanf("%s", S);
	int A, B, C, D;
	scanf("%d%d%d%d", &A, &B, &C, &D);
	for (int i = 0;; ++i) {
		if (i == A || i == B || i == C || i == D) {
			printf("\"");
		}
		if (S[i] == '\0')
			break;
		printf("%c", S[i]);
	}
	puts("");
	return 0;
}
