#include <cstdio>

int main(void)
{
	int numTests;
	scanf("%d", &numTests);
	for (int i = 1; i <= numTests; ++i) {
		int sMax;
		scanf("%d", &sMax);
		int answer = 0;
		int numStands = 0;
		for (int j = 0; j <= sMax; ++j) {
			char ch;
			scanf(" %c", &ch);
			int num = ch - '0';
			if (j <= numStands) {
				numStands += num;
			} else {
				++answer;
				++numStands;
				numStands += num;
			}
			// printf("j, numStands, answer = %d, %d, %d\n", j, numStands, answer);
		}
		printf("Case #%d: %d\n", i, answer);
	}
	return 0;
}
