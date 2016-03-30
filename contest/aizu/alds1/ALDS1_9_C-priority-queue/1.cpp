#include <cstdio>
#include <vector>
using namespace std;

int size;
int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

void insert(vector<int> *S, int key)
{
	...
}

int main(void)
{
	vector<int> *S = new vector<int>();
	char cs[8];
	while (true) {
		scanf("%s", cs);
		if (cs[2] == 'd')	// "end"
			break;
		if (cs[2] == 's') {	// "insert"
			int key;
			scanf("%d", &key);
		}
	}
	return 0;
}
