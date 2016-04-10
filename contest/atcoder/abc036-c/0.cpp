#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int N;
vector<int> *a;

void printVector(vector<int> *v)
{
	int size = v->size();
	for (int i = 0; i < size; i++) {
		printf(" %d", v->at(i));
	}
	printf("\n");
}

int main(void)
{
	scanf("%d", &N);
	a = new vector<int>();
	for (int i = 0; i < N; i++) {
		int weight;
		scanf("%d", &weight);
		a->push_back(weight);
	}
	// printVector(a);
	vector<int> *sorted = new vector<int>();
	for (int i = 0; i < N; i++) {
		sorted->push_back(a->at(i));
	}
	sort(sorted->begin(), sorted->end());
	// printVector(sorted);
	/*int numOriginals = 1;
	int prev = sorted->at(0);
	for (int i = 1; i < N; i++) {
		int num = sorted->at(i);
		if (num != prev) {
			numOriginals++;
			prev = num;
		}
		}*/
	// printf("numOriginals = %d\n", numOriginals);
	map<int, int> *bFromA = new map<int, int>();
	int bNum = 0;
	int prev = sorted->at(0);
	(*bFromA)[prev] = bNum;
	bNum++;
	for (int i = 1; i < N; i++) {
		int num = sorted->at(i);
		if (num != prev) {
			(*bFromA)[num] = bNum;
			bNum++;
			prev = num;
		}
	}
	for (int i = 0; i < N; i++) {
		int aNum = a->at(i);
		bNum = (*bFromA)[aNum];
		printf("%d\n", bNum);
	}
	return 0;
}
