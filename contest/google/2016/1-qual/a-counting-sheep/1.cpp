#include <algorithm>
#include <cstdio>
using namespace std;

int digits[10];
int numInsomnias;
int iMax = -1;

int solve(int N)
{
	if (N == 0) {
		return -1;
	}
	for (int i = 0; i < 10; i++) {
		digits[i] = 0;
	}
	for (int i = 0; i < 100; i++) {
		int i1N = (i + 1) * N;
		int num1 = i1N;
		bool isComplete;
		while (num1) {
			int digit = num1 % 10;
			digits[digit] = 1;
			isComplete = true;
			for (int j = 0; j < 10; j++) {
				if (!digits[j]) {
					isComplete = false;
				}
			}
			if (isComplete) {
				break;
			}
			num1 = num1 / 10;
		}
		if (isComplete) {
			return i1N;
		}
	}
	printf("Error.\n");
}

int main(void)
{
	int T; // [1, 100]. numTestCases.
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);
		int answer = solve(N);
		printf("Case #%d: ", i + 1);
		if (answer == -1) {
			printf("INSOMNIA\n");
		} else {
			printf("%d\n", answer);
		}
	}
	return 0;
}
