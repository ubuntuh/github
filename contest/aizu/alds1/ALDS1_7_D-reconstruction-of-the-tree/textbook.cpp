// Accepted.
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, pos;
vector<int> pre, in, post;	// それぞれ preorder、inorder、postorder にノードを格納する。

void rec(int l, int r)	// rec、l、r は、recursive、left、right の意味でしょう。[l, r) はコンテナ in における範囲を意味します。
{
	if (l >= r)
		return;
	int root = pre[pos++];
	// int m = distance(in.begin(), find(in.begin(), in.end(), root));
	// [in.begin(), in.end()) の範囲で値 root の位置を得ます。
	vector<int>::iterator rootItr = find(in.begin(), in.end(), root);
	// in.begin() と rootItr の距離を得ます。
	int m = distance(in.begin(), rootItr);
	// postorder においては、左部分木、右部分木、根の順で巡回します。
	rec(l, m);
	rec(m + 1, r);
	post.push_back(root);
}

void solve()
{
	pos = 0;
	rec(0, pre.size());
	for (int i = 0; i < n; ++i) {	// rec() によって完成した postorder なデータを出力します。
		if (i)
			cout << " ";
		cout << post[i];
	}
	cout << endl;
}

int main()
{
	int k;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		pre.push_back(k);
	}	// preorder なデータは入力により完成した。
	for (int i = 0; i < n; ++i) {
		cin >> k;
		in.push_back(k);
	}	// inorder なデータは入力により完成した。
	solve();
	return 0;
}
