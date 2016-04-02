// Accepted.
#include <cstdio>
#include <queue>
using namespace std;

int n, adjMat[100][100], distances[100];

void dfs(int node, int distance)
{
	distances[node] = distance;
	for (int i = 0; i < n; i++) {
		if (adjMat[node][i] == 0)
			continue;
		int child = i;
		if (distances[child] == -1 || distances[node] + 1 < distances[child])
			dfs(child, distance + 1);
	}
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		distances[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		int node, degree;
		scanf("%d%d", &node, &degree);
		node--;
		for (int j = 0; j < degree; j++) {
			int dst;
			scanf("%d", &dst);
			dst--;
			adjMat[node][dst] = 1;
		}
	}
	dfs(0, 0);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", i + 1, distances[i]);
	}
	return 0;
}
