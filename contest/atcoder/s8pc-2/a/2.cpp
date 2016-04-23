// Accepted.
#include <cstdio>

int main(void)
{
	int required = 1;
	int answer = 0;
	while (true) {
		char c;
		int result = scanf("%c", &c);
		if (result != 1) {
			break;
		}
		int input;
		if (c == 'I') {
			input = 1;
		} else if (c == 'O') {
			input = 0;
		} else {
			break;
		}
		if (input == required) {
			answer++;
			required = (required + 1) % 2;
		}
	}
	if (answer != 0 && answer % 2 == 0) {
		answer--;
	}
	printf("%d\n", answer);
	return 0;
}
