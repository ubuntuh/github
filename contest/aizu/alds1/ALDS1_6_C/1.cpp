#include <algorithm>
#include <cstdio>
using namespace std;

int n, A[100000], A0[100000];
char C[100000], C0[100000];

int partition(int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; ++j) {
		if (A[j] <= x) {
			++i;
			swap(A[i], A[j]);
			swap(C[i], C[j]);
		}
	}
	swap(A[i + 1], A[r]);
	swap(C[i + 1], C[r]);
	return i + 1;
}

void quickSort(int p, int r)
{
	if (p < r) {
		int q = partition(p, r);
		quickSort(p, q - 1);
		quickSort(q + 1, r);
	}
}

bool isStable()
{
	for (int i = 0; i < n; ++i) {
		int v = A[i];
		int j1 = 0;
		int j2 = 0;
		for (; j1 < n; ++j1) {
			if (A[j1] == v) {
				while (A0[j2] != v) ++j2;
				// printf("j1, j2, C[j1], C0[j2] = %d, %d, %c, %c\n", j1, j2, C[j1], C[j2]);
				if (C[j1] != C0[j2]) return false;
				++j2;
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %c%d", &C[i], &A[i]);
		C0[i] = C[i];
		A0[i] = A[i];
	}
	quickSort(0, n - 1);
	if (isStable()) puts("Stable");
	else puts("Not stable");
	for (int i = 0; i < n; ++i)
		printf("%c %d\n", C[i], A[i]);
	return 0;
}
