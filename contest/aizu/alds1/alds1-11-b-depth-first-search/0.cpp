// Accepted.
#include <cstdio>

int numNodes, matrix[100][100], startTime[100], endTime[100];

int dfs(int node, int time)
{
	if (startTime[node] != 0)
		return time;	// 以前に探索済みの頂点なので改めて探索しない。
	startTime[node] = time;
	time++;
	for (int dst = 0; dst < numNodes; dst++) {	// ありうるリンク先について。
		if (matrix[node][dst] == 0)
			continue;
		// 今や dst は実在するリンク先である。
		time = dfs(dst, time);
	}
	endTime[node] = time;
	time++;	// 帰るのにも時間がかかる。
	return time;
}

int main(void)
{
	scanf("%d", &numNodes);
	for (int i = 0; i < numNodes; i++) {
		int nodeId, degree;
		scanf("%d%d", &nodeId, &degree);
		nodeId--;
		for (int j = 0; j < degree; j++) {
			int dst;
			scanf("%d", &dst);
			dst--;
			matrix[nodeId][dst] = 1;	// 隣接行列 (adjacency matrix) で表す。
		}
	}
	int time = 1;
	for (int i = 0; i < numNodes; i++) {
		time = dfs(i, time);
	}
	for (int i = 0; i < numNodes; i++) {
		printf("%d %d %d\n", i + 1, startTime[i], endTime[i]);
	}
	return 0;
}
