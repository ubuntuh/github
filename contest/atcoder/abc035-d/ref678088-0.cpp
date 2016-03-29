// reference = http://abc035.contest.atcoder.jp/submissions/678088
// Accepted.
#include <climits>
#include <cstdio>
#include <queue>	// priority_queue
#include <utility>	// pair
using namespace std;

typedef vector<long> Longs;
typedef pair<long, int> CostNode;
struct Edge {
	int dst;
	int cost;
};
typedef vector<Edge> Edges;
typedef vector<Edges> Edgess;

Longs dijkstra(Edgess &edgess, int start)	// 辺の vector の vector と初期位置を受けとって、それぞれの頂点への最小コストを返す。
{
	int N = edgess.size();
	Longs costs(N, LONG_MAX);	// 各頂点への最小コストを大きな数で初期化する。
	priority_queue<CostNode, vector<CostNode>, greater<CostNode> > q;	// 優先度付き待ち行列。昇順。
	costs[start] = 0;	// 初期位置までのコストは 0 である。
	q.push(CostNode(0, start));	// 頂点 start までのコストは 0 である。
	while (q.size()) {
		long cost = q.top().first;
		int node = q.top().second;
		q.pop();
		if (costs[node] < cost)	// すでにより良い経路が見つかっている。
			continue;
		Edges edges = edgess[node];	// 頂点 node から発する辺らについて。
		for (Edges::iterator it = edges.begin(); it != edges.end(); ++it) {
			long newCost = cost + it->cost;
			if (costs[it->dst] > newCost) {	// 最短経路が更新できる。
				costs[it->dst] = newCost;
				q.push(CostNode(newCost, it->dst));	// 新たなデータについて調べる必要がある。
			}
		}
	}
	return costs;
}

int main(void)
{
	int N, M, T;	// 町の数、道の数、制限時間。
	scanf("%d%d%d", &N, &M, &T);
	Longs A(N);
	for (int i = 0; i < N; ++i)
		scanf("%ld", &A[i]);	// i 番目の町に滞在したときに得られる金額。[1, 100000]。
	Edgess edgess(N);
	Edgess reversedEdgess(N);
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);	// 町 a から町 b には cost c で行ける。
		--a;
		--b;
		edgess[a].push_back((Edge){b, c});
		reversedEdgess[b].push_back((Edge){a, c});	// 初期位置に戻る最短経路を効率的に求めるために、矢が逆向きになった有向グラフを使う。
	}
	Longs minCosts = dijkstra(edgess, 0);
	Longs rMinCosts = dijkstra(reversedEdgess, 0);
	long answer = 0;
	for (int i = 0; i < N; ++i) {
		if (minCosts[i] == LONG_MAX || rMinCosts[i] == LONG_MAX)
			continue;
		long stay = T - (minCosts[i] + rMinCosts[i]);	// それぞれの町に滞在できる時間とは、制限時間から、その町への最短時間とその町から帰る最短時間を除いた時間である。
		if (stay > 0)	// 与えられた制限時間で、その町に到達可能である。
			answer = max(answer, A[i] * stay);	// 最適解を全探索。
	}
	printf("%ld\n", answer);
	return 0;
}
