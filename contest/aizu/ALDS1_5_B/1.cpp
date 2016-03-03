// Accepted.
#include <climits>
#include <cstdio>

#define INFTY INT_MAX

/*
 * 添字 left から mid - 1 までと、mid から right - 1 までが、それぞれすでに整列済みである配列 A を取って、添字 left から right - 1 までを整列済みにし、データを比較した回数を返します。
 * n1 = mid - left、n2 = right - mid として、計算量は O(n1 + n2) です。
 */
int merge(int *A, int left, int mid, int right)
{
	int n1 = mid - left; // n1 は左側の配列の要素数です。
	int n2 = right - mid;
	int *L = new int[n1 + 1]; // 番兵ための場所として 1 を追加します。
	int *R = new int[n2 + 1];
	for (int i = 0; i <= n1 - 1; ++i) // 単にコピーします。
		L[i] = A[left + i];
	for (int i = 0; i <= n2 - 1; ++i)
		R[i] = A[mid + i];
	L[n1] = INFTY; // 番兵を置きます。要求定義により、要素の最大値は 1000000000 であるため、INFTY = INT_MAX は衝突しません。
	R[n2] = INFTY;
	int i = 0;
	int j = 0;
	int numCompared = 0; // 設問のために、比較回数を数えます。
	for (int k = left; k <= right - 1; ++k) {
		if (L[i] <= R[j]) { // 配列 L の要素の方が小さい場合です。
			A[k] = L[i]; // 配列 A を上書きしていきます。
			++i;
		} else {
			A[k] = R[j];
			++j;
		}
		++numCompared;
	}
	delete[] L; // ローカルで一時的に使った配列 L を delete します。
	delete[] R;
	return numCompared;
}

/*
 * 配列 A の添字 left から right - 1 までを整列します。
 */
int mergeSort(int *A, int left, int right) {
	int numCompared = 0;
	if (left + 1 < right) { // 部分配列の要素数が 2 以上の場合のみ整列が必要です。
		int mid = (left + right) / 2; // 奇数個の場合、右側の方が 1 つ長くなります。
		numCompared += mergeSort(A, left, mid); // A[left] から A[mid - 1] を再帰的に整列します。
		numCompared += mergeSort(A, mid, right);
		numCompared += merge(A, left, mid, right); // 整列済みの 2 つの部分を merge します。
	}
	return numCompared;
}

int main()
{
	int n, S[500000];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &S[i]);
	int numCompared = mergeSort(S, 0, n);
	for (int i = 0; i < n; ++i) {
		printf("%d", S[i]);
		if (i < n - 1) printf(" ");
		else printf("\n");
	}
	printf("%d\n", numCompared);
	return 0;
}
