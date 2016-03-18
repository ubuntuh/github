// Time Limit Exceeded。部分点 50。
// 一部の（小さな）入力について Accepted。
#include <cstdio>	// scanf, printf
#include <queue>	// queue
#include <utility>	// pair
using namespace std;

int bfs(int w, int h)	// breadth-first search.
{
	queue<pair<int, int> > *q = new queue<pair<int, int> >;
	pair<int, int> *p = new pair<int, int>;
	p->first = w;
	p->second = h;
	q->push(*p);
	int numNodes = 0;
	while (!q->empty()) {
		// printf("size = %ld\n", q->size());
		pair<int, int> *here;
		here = &q->front();
		q->pop();
		if (here->first == -1 || here->second == -1)
			continue;
		// printf("w, h = %d, %d\n", here->first, here->second);
		if (here->first == 0 && here->second == 0) {
			++numNodes;
			continue;
		}
		
		pair<int, int> *left = new pair<int, int>;
		left->first = here->first;
		left->second = here->second - 1;
		q->push(*left);
		
		pair<int, int> *right = new pair<int, int>;
		right->first = here->first - 1;
		right->second = here->second;
		q->push(*right);
	}
	return numNodes;
}

int main(void)
{
	int W, H;
	scanf("%d%d", &W, &H);
	--W;
	--H;
	printf("%d\n", bfs(W, H));
	return 0;
}
