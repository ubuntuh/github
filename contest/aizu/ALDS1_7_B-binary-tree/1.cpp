#include <algorithm>
#include <cstdio>
using namespace std;

#define N_MAX 25
#define NIL -1
int n, parents[N_MAX], leftChildren[N_MAX], rightChildren[N_MAX];

int getSibling(int nodeId)	// O(1).
{
	int parent = parents[nodeId];
	if (parent == NIL)
		return NIL;
	if (leftChildren[parent] == nodeId)
		return rightChildren[parent];
	else return leftChildren[parent];
}

int getDegree(int nodeId)	// O(1).
{
	int degree = 0;
	if (leftChildren[nodeId] != NIL)
		++degree;
	if (rightChildren[nodeId] != NIL)
		++degree;
	return degree;
}

int getDepth(int nodeId)	// O(log(n)).
{
	int depth = 0;
	for (int node = parents[nodeId]; node != NIL; node = parents[node])
		++depth;
	return depth;
}

int getHeight(int nodeId)	// O(n).
{
	if (nodeId == NIL)
		return -1;
	return 1 + max(getHeight(leftChildren[nodeId]), getHeight(rightChildren[nodeId]));
}

const char *types[] = {"root", "internal node", "leaf"};
const char *getType(int nodeId)	// O(1).
{
	if (parents[nodeId] == NIL)
		return types[0];
	if (getDegree(nodeId) == 0)
		return types[2];
	return types[1];
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)	// O(n).
		parents[i] = leftChildren[i] = rightChildren[i] = NIL;
	for (int i = 0; i < n; ++i) {	// O(n).
		int nodeId, leftChild, rightChild;
		scanf("%d%d%d", &nodeId, &leftChild, &rightChild);
		if (leftChild != NIL) {
			leftChildren[nodeId] = leftChild;
			parents[leftChild] = nodeId;
		}
		if (rightChild != NIL) {
			rightChildren[nodeId] = rightChild;
			parents[rightChild] = nodeId;
		}
	}
	for (int i = 0; i < n; ++i) {	// O(n * n).
		int parent = parents[i];
		int sibling = getSibling(i);
		int degree = getDegree(i);
		int depth = getDepth(i);
		int height = getHeight(i);	// O(n).
		const char *type = getType(i);
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", i, parent, sibling, degree, depth, height, type);
	}
	return 0;
}
