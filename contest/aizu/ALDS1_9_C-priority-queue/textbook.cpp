// Accepted.
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 2000000
#define INFTY (1 << 30)
int H, A[MAX + 1];
void maxHeapify(int i)	// A[i] を max heap 条件を満たすまで木の葉に向かって下降させます。
{
	int l, r, largest;
	l = 2 * i;
	r = 2 * i + 1;
	if (l <= H && A[l] > A[i])
		largest = l;
	else
		largest = i;
	if (r <= H && A[r] > A[largest])
		largest = r;
	if (largest != i) {
		swap(A[i], A[largest]);
		maxHeapify(largest);
	}
}
int extract()	// max heap の最大の要素を取得して削除します。
{
	int maxv;	// max value.
	if (H < 1)
		return -INFTY;	// エラー: ヒープアンダーフロー
	maxv = A[1];	// max heap においては根が最大である。
	A[1] = A[H--];	// 末尾の要素を根に移動し、配列の大きさを減らす。
	maxHeapify(1);	// max heap 条件を成立させる。
	return maxv;
}
void increaseKey(int i, int key)	// A[i] に key を追加して、max heap 条件を満たすように上昇させます。
{
	if (key < A[i])
		return;	// エラー: 新しいキーは現在のキーより小さい
	A[i] = key;
	while (i > 1 && A[i / 2] < A[i]) {	// 親があって、親より大きい。
		swap(A[i], A[i / 2]);
		i /= 2;
	}
}
void insert(int key)	// 優先度付きキューに key を挿入する。
{
	++H;
	A[H] = -INFTY;
	increaseKey(H, key);	// A[H] に key を設定する。
}
int main()
{
	int key;
	char com[10];
	while (1) {
		scanf("%s", com);
		if (com[0] == 'e' && com[1] == 'n')
			break;
		if (com[0] == 'i') {
			scanf("%d", &key);
			insert(key);
		} else {
			printf("%d\n", extract());
		}
	}
	return 0;
}
