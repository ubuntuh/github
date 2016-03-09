// Correct!
#include <cstdio>

int main(void)
{
	int numTest;	// 1 <= numTest <= 100.
	scanf("%d", &numTest);
	for (int caseNum = 1; caseNum <= numTest; ++ caseNum) {
		int answer1;
		scanf("%d", &answer1);
		int cards1[4 + 1][4 + 1];
		for (int row = 1; row <= 4; ++row) {
			for (int col = 1; col <= 4; ++col) {
				scanf("%d", &cards1[row][col]);
			}
		}
		int answer2;
		scanf("%d", &answer2);
		int cards2[4 + 1][4 + 1];
		for (int row = 1; row <= 4; ++row) {
			for (int col = 1; col <= 4; ++col) {
				scanf("%d", &cards2[row][col]);
			}
		}
		int numAvailable = 0;
		int lastAvailable = -1;
		for (int col1 = 1; col1 <= 4; ++col1) {
			for (int col2 = 1; col2 <= 4; ++col2) {
				if (cards1[answer1][col1] == cards2[answer2][col2]) {
					++numAvailable;
					lastAvailable = cards1[answer1][col1];
					break;
				}
			}
		}
		printf("Case #%d: ", caseNum);
		if (numAvailable == 0)
			puts("Volunteer cheated!");
		else if (numAvailable == 1)
			printf("%d\n", lastAvailable);
		else
			puts("Bad magician!");
				
	}
	return 0;
}
