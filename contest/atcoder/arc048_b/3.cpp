// Accepted.
#include <cstdio>

int N, R[100001], H[100001];
int rating[100001], rCumSum[100001], hand[100001][3];

void print() {
	for (int i = 1; i <= 100000; ++i) {
		if (rating[i] == 0) continue;
		printf("rating, numRating, cumsum, [numHands] = %d, %d, %d, [%d, %d, %d]\n", i, rating[i], rCumSum[i], hand[i][0], hand[i][1], hand[i][2]);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &R[i], &H[i]);
		--H[i];
	}
	for (int i = 1; i <= N; ++i) {
		++rating[R[i]];
		++hand[R[i]][H[i]];
	}
	rCumSum[1] = rating[1];
	for (int i = 2; i <= 100000; ++i) {
		rCumSum[i] = rCumSum[i - 1] + rating[i];
	}
	// print();
	int numWin, numLose, numDraw;
	for (int i = 1; i <= N; ++i) {
		// printf("\tActor #%d\n", i);
		numWin = numLose = 0;
		if (R[i] != 0) {
			numWin += rCumSum[R[i] - 1];
			// printf("\tnumWin from rating = %d\n", numWin);
		}
		numLose += rCumSum[100000] - rCumSum[R[i]];
		// printf("\tnumLose from rating = %d\n", numLose);
		numWin += hand[R[i]][(H[i] + 1) % 3];
		numLose += hand[R[i]][(H[i] + 2) % 3];
		numDraw = hand[R[i]][H[i]] - 1;
		printf("%d %d %d\n", numWin, numLose, numDraw);	
	}
	return 0;
}
