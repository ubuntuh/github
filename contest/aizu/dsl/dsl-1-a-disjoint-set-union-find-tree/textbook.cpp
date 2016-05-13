// Accepted.
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
	vector<int> rank;	// rank[i] ノード i を根とする木の高さである。
	vector<int> p;	// p[i] はノード i の親である。ただし根の親は自分自身である。
	// DisjointSet() {}
	DisjointSet(int size) {	// ノード 0 からノード size - 1 までを要素とする Disjoint Sets Forest を生成する。
		rank.resize(size, 0);
		p.resize(size, 0);
		for (int i = 0; i < size; i++) {
			makeSet(i);
		}
	}
	void makeSet(int x) {	// 要素が x ただ 1 つである新しい集合を作る。
		p[x] = x;	// 根の親は自分自身である。
		rank[x] = 0;	// x を根とする木の高さは 0 である。
	}
	bool same(int x, int y) {	// ノード x とノード y とが同じ集合に属していれば true。
		// ノード x と y が同じ集合に属しているとは、x を含む disjoint set と y を含む disjoint set が同一であるということである。
		return findSet(x) == findSet(y);
	}
	void unite(int x, int y) {	// ノード x を含む集合とノード y を含む集合とを合併する。
		link(findSet(x), findSet(y));
	}
	void link(int x, int y) {
		if (rank[x] > rank[y]) {
			p[y] = x;	// 低い方の木を高い方の木に合併する。
		} else {
			p[x] = y;	// disjoint set x を disjoint set y に合併する。
			if (rank[x] == rank[y]) {	// 特に、同じ高さの木を合併した時には全体の高さが 1 増加する。
				rank[y]++;
			}
		}
	}
	int findSet(int x) {	// findSet(x) はノード x を含む disjoint set である。
		// ノード x を含む disjoint set とは、p[x] が x 自身ならば x である (base case)。そうでないならば、ノード p[x] を含む disjoint set である。
		if (x != p[x]) {
			p[x] = findSet(p[x]);	// 経路圧縮。経路圧縮によって rank の値がおかしくなるが問題ないらしい。
		}
		return p[x];

		// もし経路圧縮を行わないならば次のようなコードになるだろう。
		// while (x != p[x]) {
		// 	x = p[x];
		// }
		// return p[x];
	}
};
int main(void)
{
	int n;	// 要素の数である。要素の名前は 0, 1, ..., n - 1 である。
	int a;
	int b;
	int q;	// クエリの数である。
	int t;
	cin >> n >> q;
	DisjointSet ds = DisjointSet(n);
	for (int i = 0; i < q; i++) {
		cin >> t >> a >> b;	// 与えられる命令は常に引数が 2 つである。よって与えられる命令が何であれ、引数を a, b に得る。ただし問題文では x, y となっている。
		if (t == 0) {	// 命令番号 0 は unite 命令である。a を含む集合と b を含む集合を合併せよ。
			ds.unite(a, b);
		} else if (t == 1) {	// 命令番号 1 は same 命令である。a と b が同じ集合に属しているなら 1、そうでないならば 0 を出力せよ。
			if (ds.same(a, b)) {
				cout << 1 << endl;
			} else {
				cout << 0 << endl;
			}
		}
	}
	return 0;
}
