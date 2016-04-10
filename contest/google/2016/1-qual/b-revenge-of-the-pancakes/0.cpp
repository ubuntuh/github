#include <cstdio>

int T;	// numTestCases. [1, 100].
char S[101];

int main(void)
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%s", S);
		int numFlips = 0;
		char prev = S[0];
		char last = S[0];
		for (int j = 1; S[j] != '\0'; j++) {
			if (S[j] != prev) {
				numFlips++;
				prev = S[j];
			}
			last = S[j];
		}
		if (last == '-') {
			numFlips++;
		}
		printf("Case #%d: %d\n", i + 1, numFlips);
	}
	return 0;
}
