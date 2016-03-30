// 間違ったプログラム。
// 兄弟の順序を保持できませんでした。しかも計算量が多いです。
#include <cstdio>

int numNodes, parents[100000], depths[100000];
bool isLeaf[100000];
const char *types[] = {"root", "internal node", "leaf"};

int main(void)
{
	scanf("%d", &numNodes);
	for (int i = 0; i < numNodes; ++i) {
		parents[i] = -1;
		isLeaf[i] = true;
	}
	for (int i = 1; i <= numNodes; ++i) {
		int nodeId;
		int numChildren;
		scanf("%d%d", &nodeId, &numChildren);
		for (int j = 1; j <= numChildren; ++j) {
			int childId;
			scanf("%d", &childId);
			parents[childId] = nodeId;
		}
	}
	for (int i = 0; i < numNodes; ++i) {
		int depth = 0;
		for (int j = i; parents[j] != -1; j = parents[j]) {
			++depth;
			isLeaf[parents[j]] = false;
		}
		depths[i] = depth;
	}
	for (int i = 0; i < numNodes; ++i) {
		int parentId = parents[i];
		int depth = depths[i];
		int type;
		if (parentId == -1) {
			type = 0;
		} else if (isLeaf[i]) {
			type = 2;
		} else {
			type = 1;
		}
		printf("node %d: parent = %d, depth = %d, %s, [", i, parentId, depth, types[type]);
		bool isFirstChild = true;
		for (int j = 0; j < numNodes; ++j) {
			if (parents[j] == i) {
				if (isFirstChild) {
					isFirstChild = false;
				} else {
					printf(", ");
				}
				printf("%d", j);
			}
		}
		printf("]\n");
	}
	return 0;
}
