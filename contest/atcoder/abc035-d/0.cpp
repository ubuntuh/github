#include <cstdio>
#include <vector>
using namespace std;

struct Arrow {
	int dst;
	int cost;
};

int N, M, T, A[100000];
vector<Arrow *> arrowss[100000];

int dfs(int src)
{
	...
}

int main(void)
{
	scanf("%d%d%d", &N, &M, &T);
	for (int i = 0; i < N; ++i)
		scanf("%d", &A[i]);
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		Arrow *arrow = new Arrow();
		arrow->dst = b;
		arrow->cost = c;
		arrowss[a].push_back(arrow);
	}
	return 0;
}
