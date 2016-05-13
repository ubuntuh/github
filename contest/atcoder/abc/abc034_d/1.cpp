#include <cstdio>

void printArray(double *array, int left, int right)
{
	for (int i = left; i <= right; ++i) {
		printf(" %.2f", array[i]);
	}
	puts("");
}

int partition(double *array, int left, int right)
{
	static int numCall;
	++numCall;
	// printf("partition#%d - left, right = %d, %d\n", numCall, left, right);
	double border = array[right];
	int right2 = right - 1;
	int biggerEnd = left - 1;
	for (int i = left; i <= right2; ++i) {
		if (array[i] >= border) {
			++biggerEnd;
			double tmp = array[i];
			array[i] = array[biggerEnd];
			array[biggerEnd] = tmp;
		}
	}
	++biggerEnd;
	array[right] = array[biggerEnd];
	array[biggerEnd] = border;
	return biggerEnd;
}

void partitionExchangeSort(double *array, int left, int right)
{
	static int numCall;
	++numCall;
	// printf("partitionExchangeSort#%d - left, right = %d, %d\n", numCall, left, right);
	if (right - left <= 0)
		return;
	int border = partition(array, left, right);
	partitionExchangeSort(array, left, border - 1);
	partitionExchangeSort(array, border + 1, right);
}

int N, K, w[1001];
double p[1001], salt[1001];

bool isAvailable(double arg)
{
	for (int i = 1; i <= N; ++i) {
		salt[i] = w[i] * (p[i] - arg);
	}
	partitionExchangeSort(salt, 1, N);
	double saltSum = 0;
	for (int i = 1; i <= K; ++i) {
		saltSum += salt[i];
	}
	bool result = saltSum >= 0;
	return result;
}

double binarySearch(double left, double right) {
	static int numCall;
	++numCall;
	if (right - left < 0.0000000001)
		return (left + right) / 2;
	double middle = (left + right) / 2;
	// printf("binarySearch#%d - left, mid, right = %f, %f, %f\n", numCall, left, middle, right);
	if (isAvailable(middle))
		return binarySearch(middle, right);
	else
		return binarySearch(left, middle);
}

int main(void)
{
	scanf("%d%d", &N, &K);
	int pTmp[1001];
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &w[i], &pTmp[i]);
		p[i] = pTmp[i] / 100.;
	}
	double f = binarySearch(0, 1);
	printf("%.9f\n", 100 * f);
	return 0;
}
