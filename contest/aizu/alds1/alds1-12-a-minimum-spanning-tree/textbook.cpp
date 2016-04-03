// Accepted.
#include <iostream>
using namespace std;

static const int MAX   = 100;	// 頂点の最大値。
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY  = 1;
static const int BLACK = 2;

int n;	// 頂点の数。
int M[MAX][MAX];	// 隣接行列。

int prim(void)	// プリム法 (Prim's algorithm) で最小全域木 (minimum spanning tree, MST) を求め、その辺の重みの総和を返す。
{
	int u;
	int minv;
	int d[MAX];	// 重みが最小の辺の重み。
	int p[MAX];	// p[i] は頂点 i の親である。
	int color[MAX];	// color[i] は頂点 i の訪問状態を表す。

	for (int i = 0; i < n; i++) {	// 初期化する。
		d[i] = INFTY;
		p[i] = -1;
		color[i] = WHITE;
	}

	d[0] = 0;	// 頂点 0 を根とする。

	while (1) {
		minv = INFTY;	// すでに見つかった最も軽い辺の重さを格納する。
		u = -1;	// 新たに MST に加えるべき頂点を u に求める。
		for (int i = 0; i < n; i++) {	// 全ての頂点について。
			if (minv > d[i] && color[i] != BLACK) {	// まだ MST に加わっておらず、最も軽いものを探す。
				u = i;
				minv = d[i];
			}
		}
		if (u == -1)
			break;	// もはや MST に加える頂点が無いのであれば MST の構築は終了である。
		color[u] = BLACK;	// 頂点 u を MST に加える。
		for (int v = 0; v < n; v++) {	// 全ての頂点について。
			if (color[v] != BLACK && M[u][v] != INFTY) {	// まだ MST に加わっておらず、MST の新たな頂点 u から繋がっている。
				if (d[v] > M[u][v]) {	// これまでに見つかったものよりも小さい。
					d[v] = M[u][v];	// 重みを記録する。
					p[v] = u;	// 頂点 v の親は u である。
					color[v] = GRAY;	// d が与えられた頂点は状態 GRAY とする。
				}
			}
		}
	}
	int sum = 0;	// MST の辺の重みの総和を求める。
	for (int i = 0; i < n; i++) {	// 全ての辺について。
		if (p[i] != -1)	// 親が存在する。
			sum += M[i][p[i]];	// 親への重みを MST の重みの総和に加える。
	}
	return sum;
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int e;
			cin >> e;
			M[i][j] = (e == -1) ? INFTY : e;	// 入力される隣接行列をそのまま M に隣接行列として組み立てる。ただし、辺が存在しない関係については、-1 ではなく巨大な数を入れる。なお制約により、入力されるグラフは連結である。
		}
	}

	cout << prim() << endl;
	return 0;
}
