// Accepted.
// 最長共通部分列 (longest common subsequence, LCS) の長さを求める。
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static const int N = 1000;

int lcs(string X, string Y)
{
	int c[N + 1][N + 1];	// c[i][j] は、X[i] までの X と Y[j] までの Y の LCS の長さである。
	int m = X.size();
	int n = Y.size();
	int maxl = 0;
	X = ' ' + X;	// X[0] に空白を挿入
	Y = ' ' + Y;	// Y[0] に空白を挿入
	c[0][0] = 0;
	for (int i = 1; i <= m; ++i)
		c[i][0] = 0;
	for (int j = 1; j <= n; ++j)
		c[0][j] = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (X[i] == Y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			} else {
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			}
			maxl = max(maxl, c[i][j]);
			cout << " " << maxl;
		}
		cout << endl;
	}
	return maxl;
}

int main(void)
{
	string s1, s2;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s1 >> s2;
		cout << lcs(s1, s2) << endl;
	}
	return 0;
}
