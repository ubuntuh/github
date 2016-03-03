#include <cstdio>

int n;

void CountingSort(int *A, int *B, int k)
{
	int *C = new int[2000000];
	for (int i = 0; i <= k; ++i)
		C[i] = 0;
	for (int j = 1; j <= n; ++j)
		++C[A[j - 1]];
	for (int i = 1; i <= k; ++i)
		C[i] = C[i] + C[i - 1];
	for (int j = n; 0 <= j; --j) {
		B[C[A[j - 1]] - 1] = A[j - 1];
		--C[A[j - 1]];
	}
	delete[] C;
}

int main()
{
	scanf("%d", &n);
	int k = -1;
	int *A = new int[2000000];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
		if (k < A[i])
			k = A[i];
	}
	int *B = new int[2000000];
	CountingSort(A, B, k);
	delete[] A;
	for (int i = 0; i < n; ++i) {
		printf("%d", B[i]);
		if (i < n - 1) printf(" ");
		else printf("\n");
	}
	delete[] B;
	return 0;
}
