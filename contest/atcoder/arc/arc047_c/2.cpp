#include <cstdio>
#include <list>
using namespace std;

int N; // [1, 100000]
int K; // [1, 100000] and K <= N

int main() {
    scanf("%d %d", &N, &K);
    printf("N, K = %d %d\n", N, K);
    // order / (N - 1)!
    // = (N! / K) / (N - 1)!
    // = N / K
    int quotient = N / K;
    printf("quotient = %d\n" , quotient);
    int remainder = N % K;
    printf("remainder = %d\n", remainder);
    int index;
    if (remainder) index = quotient + 1;
    else           index = quotient;
    printf("index = %d\n", index);
    return 0;
}
