// Accepted.
#include <algorithm>
#include <cstdio>
using namespace std;

/*
 * A[p] から A[r] について、A[r] 未満の部分と A[r] より大きい部分に分けます。O(n)。
 */
int partition(int *A, int p, int r)
{
	int x = A[r]; // 基準になる値です。
	int i = p - 1;
	for (int j = p; j <= r - 1; ++j) {
		if (A[j] <= x) {
			++i;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

int main()
{
	int n, A[100000];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &A[i]);
	int q = partition(A, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		if (i == q) printf("[%d]", A[i]);
		else printf("%d", A[i]);
		if (i < n - 1) printf(" ");
		else printf("\n");
	}
	return 0;
}
