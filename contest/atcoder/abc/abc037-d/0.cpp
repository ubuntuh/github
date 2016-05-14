#include <cstdio>
#include <stack>
#include <utility>
using namespace std;

int height;	// [1, 1000]
int width;	// [1, 1000]
int grid[1001][1001];
int indegreess[1001][1001];
int num_routes[1001][1001];
stack<pair<int, int> > zero_degrees;
int prime = 1000000007;
int num_moves = 4;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int main(void)
{
	scanf("%d%d", &height, &width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			scanf("%d", &grid[i][j]);
			indegreess[i][j] = 0;
			num_routes[i][j] = 1;
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			for (int k = 0; k < num_moves; k++) {
				int jj = j + dx[k];
				int ii = i + dy[k];
				if (jj < 0 || width - 1 < jj) {
					continue;
				}
				if (ii < 0 || height - 1 < ii) {
					continue;
				}
				int src = grid[i][j];
				int dst = grid[ii][jj];
				if (dst < src) {
					indegreess[ii][jj]++;
				}
			}
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (indegreess[i][j] == 0) {
				pair<int, int> pair0 = make_pair(j, i);
				zero_degrees.push(pair0);
			}
		}
	}
	while (zero_degrees.size() > 0) {
		pair<int, int> pair0 = zero_degrees.top();
		zero_degrees.pop();
		int j = pair0.first;
		int i = pair0.second;
		for (int k = 0; k < num_moves; k++) {
			int jj = j + dx[k];
			int ii = i + dy[k];
			if (jj < 0 || width - 1 < jj) {
				continue;
			}
			if (ii < 0 || height - 1 < ii) {
				continue;
			}
			int src = grid[i][j];
			int dst = grid[ii][jj];
			if (dst < src) {
				num_routes[ii][jj] = (num_routes[ii][jj] + num_routes[i][j]) % prime;
				indegreess[ii][jj]--;
				if (indegreess[ii][jj] == 0) {
					pair<int, int> pair1 = make_pair(jj, ii);
					zero_degrees.push(pair1);
				}
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			answer = (answer + num_routes[i][j]) % prime;
		}
	}
	printf("%d\n", answer);
	return 0;
}
