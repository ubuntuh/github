// Accepted.
#include <cstdio>
#include <queue>
using namespace std;

int n, adjMat[100][100], distances[100];

void bfs(int startNode, int startDist)
{
	queue<int> q;
	q.push(startNode);
	distances[startNode] = startDist;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (adjMat[node][i] == 0)
				continue;
			int child = i;
			if (distances[child] == -1 || distances[node] + 1 < distances[child]) {
				distances[child] = distances[node] + 1;
				q.push(child);
			}
		}
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
	bfs(0, 0);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", i + 1, distances[i]);
	}
	return 0;
}
