// Accepted.
#include <cstdio>

#define NIL		-1
#define PREORDER	0
#define INORDER		1
#define POSTORDER	2
#define N_MAX		25
int n, leftChildren[N_MAX], rightChildren[N_MAX];

void walk(int nodeId, int order)	// 再帰的です。O(n)。3 つの巡回順を 1 つの関数で実装します。
{
	if (nodeId == NIL)
		return;
	int left = leftChildren[nodeId];
	int right = rightChildren[nodeId];
	if (order == PREORDER) {
		printf(" %d", nodeId);
		walk(left, order);
		walk(right, order);
	} else if (order == INORDER) {
		walk(left, order);
		printf(" %d", nodeId);
		walk(right, order);		
	} else {
		walk(left, order);
		walk(right, order);		
		printf(" %d", nodeId);
	}
}

int getRoot(void)	// 根を返します。O(n * n)。親方向のリンクを持てば根の探索は O(log(n)) でしょう。親方向のリンクを持たずに根を得ようとします。
{
	for (int i = 0; i < n; ++i) {	// 全ての節について。
		bool isRootFound = true;
		for (int j = 0; j < n; ++j) {	// 全ての節について。
			if (leftChildren[j] == i) {
				isRootFound = false;	// 誰かの子であるなら i は根ではない。
				break;
			} else if (rightChildren[j] == i) {
				isRootFound = false;
				break;
			}
		}
		if (isRootFound)
			return i;	// 誰の子でもないなら i は根である。
	}
	return NIL;	// この場合は発生しない。
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int nodeId, leftChild, rightChild;
		scanf("%d%d%d", &nodeId, &leftChild, &rightChild);
		leftChildren[nodeId] = leftChild;
		rightChildren[nodeId] = rightChild;
	}
	int root = getRoot();
	puts("Preorder");
	walk(root, PREORDER);
	puts("");
	puts("Inorder");
	walk(root, INORDER);
	puts("");
	puts("Postorder");
	walk(root, POSTORDER);
	puts("");
	return 0;
}
