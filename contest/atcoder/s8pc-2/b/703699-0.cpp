// reference: submission 703699
// AC な人のアルゴリズムのコピーである。なぜこれで正しいのかわからない。
#include <cstdio>

long n;
long a[24];
int node_id_source = 0;

int dfs(int parent, int node_id, int a_index, long w)
{
	printf("dfs #%d started. parent = %d, a_index = %d, w = %ld.\n", node_id, parent, a_index, w);
	int result;
	if (w > n) {
		result = 0;
	} else if (a_index < 0) {
		result = 1;
	} else {
		if (w % a[a_index] == 0) {
			result = dfs(node_id, node_id_source++,  a_index - 1, w * a[a_index]);
		} else {
			int tmp0 = dfs(node_id, node_id_source++, a_index - 1, w);
			int tmp1 = dfs(node_id, node_id_source++, a_index - 1, w * a[a_index]);
			result = tmp0 + tmp1;
		}
	}
	printf("\tdfs #%d ended. result = %d.\n", node_id, result);
	return result;
}

int main(void)
{
	int q;
	scanf("%ld%d", &n, &q);
	for (int i = 0; i < q; i++) {
		scanf("%ld", &a[i]);
	}
	int result = dfs(-1, node_id_source++, q - 1, 1);
	printf("%d\n", result);
}
