// Accepted.
#include <cstdio>

int H;

int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

void maxHeapify(int *A, int i)	// 節点 i を根とする部分木が max heap になるよう A[i] の値を max heap の葉に向かって下降させます。
{
	int l = left(i);
	int r = right(i);
	int largest;	// 左の子、自分、右の子で値が最大のノードを選ぶ
	if (l <= H && A[l] > A[i])	// 左の子がいて自分より大きい場合。
		largest = l;
	else
		largest = i;	// 暫定的に自分が最大であるとする。
	if (r <= H && A[r] > A[largest])	// 右の子がいて他より大きい場合。
		largest = r;
	if (largest != i) {	// i の子の方が値が大きい場合
		int tmp = A[i];
		A[i] = A[largest];
		A[largest] = tmp;
		maxHeapify(A, largest);	// 再帰的に呼び出し
	}
}

void buildMaxHeap(int *A)	// ボトムアップに maxHeapify を適用することで配列 A を max heap に変換します。
{
	for (int i = H / 2; i >= 1; --i)
		maxHeapify(A, i);
}

int main(void)
{
	scanf("%d", &H);
	int A[500001];
	for (int i = 1; i <= H; ++i) {
		scanf("%d", &A[i]);
	}
	buildMaxHeap(A);
	for (int i = 1; i <= H; ++i) {
		printf(" %d", A[i]);
	}
	puts("");
	return 0;
}
