// Accepted.
#include <cstdio>

int S[100001], T, x, y, numUnknowns;
char c;

int getManhattanDistance(int x, int y)	// returns |x| + |y|.
{
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	return x + y;
}

int main(void)
{
	while (true) {
		scanf("%c", &c);
		if (c == '\n')
			break;
		if (c == 'L')
			--x;
		else if (c == 'R')
			++x;
		else if (c == 'U')
			++y;
		else if (c == 'D')
			--y;
		else
			++numUnknowns;
	}
	int manhattanDistance = getManhattanDistance(x, y);
	// printf("manhattanDistance = %d\n", manhattanDistance);
	scanf("%d", &T);
	int answer;
	if (T == 1) {
		answer = manhattanDistance + numUnknowns;
	} else {
		if (numUnknowns <= manhattanDistance)
			answer = manhattanDistance - numUnknowns;
		else if ((numUnknowns - manhattanDistance) % 2)
			answer = 1;
		else
			answer = 0;
	}
	printf("%d\n", answer);
	return 0;
}
