// Accepted.
// Using one-based indexing.
#include <cstdio>

int n;

/*
 * O(n + k)。stable。
 */
void CountingSort(int *A, int *B, int k)
{
	int *C = new int[10001]; // C[0..10000]
	for (int i = 0; i <= k; ++i) // 初期化します。
		C[i] = 0;
	for (int j = 1; j <= n; ++j) // それぞれの値の出現数を数えます。
		++C[A[j]];
	for (int i = 1; i <= k; ++i) // 累積和を求めます。
		C[i] = C[i] + C[i - 1];
	for (int j = n; 0 <= j; --j) { // 後方から処理することで stable な整列になります。
		B[C[A[j]]] = A[j]; // A[j] 以下である要素の数　C[A[j]] を用いて A[j] の B における位置を決めます。
		--C[A[j]]; // 後に重複する値を持つ要素が適切な位置に置かれるよう、C を修正します。
	}
	delete[] C;
}

int main()
{
	scanf("%d", &n);
	int k = -1;
	int *A = new int[2000001]; // A[0..2000000] 
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
		if (k < A[i])
			k = A[i];
	}
	int *B = new int[2000001];
	CountingSort(A, B, k);
	delete[] A;
	for (int i = 1; i <= n; ++i) {
		printf("%d", B[i]);
		if (i < n) printf(" ");
		else printf("\n");
	}
	delete[] B;
	return 0;
}
