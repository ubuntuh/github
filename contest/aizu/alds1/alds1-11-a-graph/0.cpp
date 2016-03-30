// Accepted.
#include <cstdio>

int n;	// number of nodes
int adjMat[100][100];	// adjacency matrix

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int u;	// node id
		int k;	// degree
		scanf("%d%d", &u, &k);
		--u;
		for (int j = 0; j < k; ++j) {
			int v;	// destination node id
			scanf("%d", &v);
			--v;
			adjMat[i][v] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d", adjMat[i][j]);
			if (j < n - 1)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}
