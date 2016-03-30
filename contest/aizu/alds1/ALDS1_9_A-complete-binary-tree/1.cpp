// Accepted.
#include <cstdio>

#define UNDEFINED 2000000001
int H, A[250];

int main(void)
{
	scanf("%d", &H);
	for (int i = 1; i <= H; ++i) {
		scanf("%d", &A[i]);
	}
	for (int i = 1; i <= H; ++i) {
		int key = A[i];
		int parent = UNDEFINED;
		if (i != 1)
			parent = A[i / 2];
		int left = UNDEFINED;
		if (2 * i <= H)
			left = A[2 * i];
		int right = UNDEFINED;
		if (2 * i + 1 <= H)
			right = A[2 * i + 1];
		printf("node %d: key = %d, ", i, key);
		if (parent != UNDEFINED)
			printf("parent key = %d, ", parent);
		if (left != UNDEFINED)
			printf("left key = %d, ", left);
		if (right != UNDEFINED)
			printf("right key = %d, ", right);
		puts("");
	}
	return 0;
}
