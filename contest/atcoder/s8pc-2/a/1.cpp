// [12, 15] or [31, 36] で WA。
#include <cstdio>

int main(void)
{
	int required = 1;
	int answer = 0;
	while (true) {
		char c;
		scanf("%c", &c);
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
	printf("%d\n", answer);
	return 0;
}
