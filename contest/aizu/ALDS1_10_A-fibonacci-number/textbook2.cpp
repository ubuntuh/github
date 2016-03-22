// Accepted.
#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;	// [0, 44]
	int F[50];	// n は 44 以下であるから、F[44] まであればよいので、int F[45] と宣言してもよい。
	F[0] = F[1] = 1;
	for (int i = 2; i <= n; ++i)	// F[44] までは必ずしも作らず F[n] まで作る。
		F[i] = F[i - 1] + F[i - 2];
	cout << F[n] << endl;
	return 0;
}
