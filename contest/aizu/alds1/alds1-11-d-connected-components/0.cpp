// Wrong Answer.
#include <cstdio>

int numNodes;	// [2, 10**5]
int numEdges;	// [0, 10**5]
int numQuestions;	// [1, 10**4]
int groupFromNode[100000];
int parentGroup[100000];

int getRootGroup(int g)
{
	int root = g;
	while (parentGroup[root])
		root = parentGroup[root];
	return root;
}

void connectGroups(int g0, int g1)
{
	int r0 = getRootGroup(g0);
	int r1 = getRootGroup(g1);
	if (r0 == r1)
		return;
	if (r0 < r1)
		parentGroup[r1] = r0;
	else
		parentGroup[r0] = r1;
}

void addEdge(int s, int t)
{
	static int groupId = 0;
	if (groupFromNode[s] == 0) {
		if (groupFromNode[t] == 0) {
			groupId++;
			groupFromNode[s] = groupId;
			groupFromNode[t] = groupId;
		} else {
			groupFromNode[s] = groupFromNode[t];
		}
	} else {
		if (groupFromNode[t] == 0) {
			groupFromNode[t] = groupFromNode[s];
		} else {
			connectGroups(groupFromNode[s], groupFromNode[t]);
		}
	}
}

int main(void)
{
	scanf("%d%d", &numNodes, &numEdges);
	for (int i = 0; i < numEdges; i++) {
		int s, t;
		scanf("%d%d", &s, &t);
		addEdge(s, t);
	}
	scanf("%d", &numQuestions);
	for (int i = 0; i < numQuestions; i++) {
		int s, t;
		scanf("%d%d", &s, &t);
		int sGroup = getRootGroup(groupFromNode[s]);
		int tGroup = getRootGroup(groupFromNode[t]);
		if (sGroup == tGroup)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
