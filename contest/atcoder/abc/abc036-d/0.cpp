#include <cstdio>
#include <list>
#include <map>
#include <set>
using namespace std;

int N;
typedef list<int> Edges;
typedef Edges::iterator EdgesIt;
typedef map<int, Edges *> Edgess;
Edgess *edgess;
set<int> *visited;

int getNumChildren(Edges *edges)
{
	int numChildren = 0;
	for (EdgesIt it = edges->begin(); it != edges->end(); ++it) {
		if (visited->find(*it) == visited->end()) {
			numChildren++;
		}
	}
	return numChildren;
}

int dfs(int node, int black, int white)
{
	static int numCall = 0;
	printf("numCall = %d\n", numCall);
	if (numCall >= 20) {
		return 0;
	}
	numCall++;
	visited->insert(node);
	printf("dfs(node=%d, black=%d, white=%d)\n", node, black, white);
	if (edgess->find(node) == edgess->end()) {
		return 0;
	}
	Edges *children = (*edgess)[node];
	// int numChildren = children->size();
	int numChildren = getNumChildren(children);
	printf("numChildren = %d\n", numChildren);
	if (numChildren < 1) {
		return 0;
	}
	int sum = ;
	for (EdgesIt it = children->begin(); it != children->end(); ++it) {
		if (visited->find(*it) != visited->end()) {
			printf("visited (%d)\n", *it);
			continue;
		}
		int tmpResult;
		tmpResult = dfs(*it, white * numChildren, white * numChildren + black);
		printf("%d %d tmpResult = %d\n", node, *it, tmpResult);
		if (tmpResult > maxResult) {
			maxResult = tmpResult;
		}
	}
	return maxResult;
}

int main(void)
{
	edgess = new Edgess();
	visited = new set<int>();
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a;
		int b;
		scanf("%d%d", &a, &b);
		a--;
		b--;

		if (edgess->find(a) == edgess->end()) {
			(*edgess)[a] = new Edges();
		}
		(*edgess)[a]->push_back(b);
		
		if (edgess->find(b) == edgess->end()) {
			(*edgess)[b] = new Edges();
		}
		(*edgess)[b]->push_back(a);
	}
	for (int i = 0; i < N; i++) {
		printf("from %d\n", i);
		if (edgess->find(i) == edgess->end()) {
			printf("nothing\n");
			continue;
		}
		Edges *edges = (*edgess)[i];
		for (EdgesIt it = edges->begin(); it != edges->end(); ++it) {
			printf(" %d", *it);
		}
		printf("\n");
	}
	int dfsResult = dfs(0, 1, 1);
	printf("%d\n", dfsResult);
	return 0;
}
