#include <algorithm>
#include <cstdio>
using namespace std;

int digits[10];
int numInsomnias;
int iMax = -1;

void test(int N)
{
	// printf("test(%d)\n", N);
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
		
		// printf("N = %d, i = %d, (i+1)*N = %d; ", N, i, i1N);
		// for (int j = 0; j < 10; j++) {
		// 	printf("%d", digits[j]);
		// }
		// puts("");
		
		if (isComplete) {
			if (i>50)
			printf("N = %d, i = %d, Answer = %d\n", N, i, i1N);
			iMax = max(iMax, i);
			return;
		}
	}
	printf("INSOMNIA?\n");
	numInsomnias++;
}

int main(void)
{
	for (int i = 0; i < 1000001; i++) {
		test(i);
	}
	printf("numInsomnias = %d\n", numInsomnias);
	printf("iMax = %d\n", iMax);
	return 0;
}
