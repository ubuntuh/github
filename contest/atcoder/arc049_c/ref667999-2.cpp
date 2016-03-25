// reference = http://arc049.contest.atcoder.jp/submissions/667999
// Accepted.
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N, A, B, x[101], y[101], u[11], v[11];
bool colored[101];	// colored[i] は頂点 i が着色されていれば true である。
vector<int> arrowss[101];	//  arrowss[i] は、頂点 i から出た矢が指す頂点らの vector である。
int indegrees[101];	// indegrees[i] は、頂点 i に向かう矢の数（入次数）である。

int bfs()	// 塗れた頂点の数を返す。
{
	for (int i = 1; i <= N; ++i)	// 全ての頂点について入次数を 0 に初期化する。
		indegrees[i] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= arrowss[i].size() - 1; ++j) {	// 頂点 i から出発する全ての矢について。
			int dstNode = arrowss[i][j];
			++indegrees[dstNode];	// 矢の先にある頂点の入次数を追加する。
		}
	}
	int result = 0;
	for (int i = 1; i <= N; ++i) {	// 全ての頂点について。
		if (indegrees[i] == 0 && !colored[i]) {	// 頂点 i の入次数が 0 でありかつ未着色である。
			queue<int> newNodes;
			colored[i] = true;	// 頂点 i を塗る。
			newNodes.push(i);
			++result;
			while(!newNodes.empty()) {	// 頂点 i を塗ったことによって直接的、間接的に塗れるようになった頂点全てについて 1 つずつ処理する。queue を用いた breadth-first search。
				int newNode = newNodes.front();
				newNodes.pop();
				for (int j = 1; j <= arrowss[newNode].size() - 1; ++j) {	// newNode から伸びる全ての矢について。
					int dstNode = arrowss[newNode][j];
					--indegrees[dstNode];	// 制約を削除する。
					if (indegrees[dstNode] == 0 && !colored[dstNode]) {	// 新たに制約が削除された頂点が塗れる。
						newNodes.push(dstNode);	// 新たに塗った頂点として追加する。
						colored[dstNode] = true;
						++result;
					}
				}
			}
		}
	}
	return result;
}

int main(void)
{
	scanf("%d", &N);
	scanf("%d", &A);
	for (int i = 1; i <= A; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	scanf("%d", &B);
	for (int i = 1; i <= B; ++i) {
		scanf("%d%d", &u[i], &v[i]);
	}
	int answer = 0;
	for (int i = 0; i < 1 << B; ++i) {	// B 個のタイプ 2 制約それぞれについて 2 種類の場合を総当り法で調べる。場合の数は 2**B 通り、すなわち 1 << B 通りである。B が最大値 10 の時 2**B は 1024 である。
		for (int j = 1; j <= N; ++j)
			colored[j] = false;	// 頂点の着色情報を（false に）初期化する。
		for (int j = 1; j <= N; ++j) {
			arrowss[j].clear();	// 矢の情報を初期化する。
			arrowss[j].push_back(-1);	// ダミーを挿入して one-based index に調整する。
		}
		for (int j = 1; j <= A; ++j)
			arrowss[y[j]].push_back(x[j]);	// タイプ 1 制約を矢に表した。
		for (int j = 1; j <= B; ++j) {	// タイプ 2 制約それぞれについて。
			if (i & 1 << j - 1)	// B ビットの i の中で、今、注目しているタイプ 2 制約 j に当たる部分は立っているか？
				colored[u[j]] = true;	// u[j] を塗らない。後の処理上、すでに塗ってあるともう塗れない。
			else
				arrowss[u[j]].push_back(v[j]);	// v[j] を塗るためには u[j] を塗らなければならない。
		}
		answer = max(answer, bfs());	// タイプ 2 制約のそれぞれの場合について、最も多く頂点が塗れるものを探す。
	}
	printf("%d\n", answer);
	return 0;
}
