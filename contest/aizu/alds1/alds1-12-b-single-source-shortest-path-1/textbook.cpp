// Accepted.
#include <iostream>
using namespace std;

static const int MAX   = 100;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY  = 1;
static const int BLACK = 2;

int n;	// 頂点数。
int M[MAX][MAX];	// 隣接行列。

void dijkstra(void)
{
	int minv;
	int d[MAX];	// d[i] に頂点 i への最短距離を求める。
	int color[MAX];

	for (int i = 0; i < n; i++) {
		d[i] = INFTY;
		color[i] = WHITE;
	}

	d[0] = 0;
	color[0] = GRAY;

	while (1) {
		minv = INFTY;
		int u = -1;
		for (int i = 0; i < n; i++) {
			if (minv > d[i] && color[i] != BLACK) {	// まだ最短経路木に加わっておらず最も近い頂点を探す。
				u = i;
				minv = d[i];
			}
		}

		if (u == -1)
			break;
		color[u] = BLACK;	// 最短経路木に加える。

		for (int v = 0; v < n; v++) {	// 全ての頂点について。
			if (color[v] != BLACK && M[u][v] != INFTY) {	// まだ最短経路木に加わっておらず、頂点 u から隣接する頂点 v を探す。
				if (d[v] > d[u] + M[u][v]) {	// 頂点 u から v へ行くことが v への最短経路であるならば、v の距離を更新する。
					d[v] = d[u] + M[u][v];
					color[v] = GRAY;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {	// 全ての辺への距離を出力する。
		cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
	}
}

int main(void)
{
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			M[i][j] = INFTY;	// 隣接行列を初期化する。
		}
	}

	int k;
	int c;
	int u;
	int v;

	for (int i = 0; i < n; i++) {
		cin >> u >> k;	// 頂点番号とその頂点の次数を得る。
		for (int j = 0; j < k; j++) {
			cin >> v >> c;	// 隣接頂点番号とそれへの有向辺の重みを得る。
			M[u][v] = c;	// 入力される隣接リスト表現のデータを隣接行列に表す。
		}
	}

	dijkstra();
	return 0;
}
