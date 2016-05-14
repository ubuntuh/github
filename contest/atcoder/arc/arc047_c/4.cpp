#include <cstdio>
long N, K, factorials[100000 + 1];
bool isUsed[100000 + 1];
int main() {
    scanf("%ld %ld", &N, &K);
    factorials[0] = factorials[1] = 1;
    for (int i = 2; i <= N; ++i) {
        factorials[i] = i * factorials[i - 1];
    }
    int oneBasedIndex = factorials[N] / K;
    int zeroBasedIndex = oneBasedIndex - 1;
    for (int i = 0; i < N; ++i) {
        printf("    zeroBasedIndex = %d\n", zeroBasedIndex);
        long numDuplications = factorials[N - 1 - i];
        printf("    numDuplications = %ld\n", numDuplications);
        long indexWithoutDuplication = zeroBasedIndex / numDuplications;
        printf("    indexWithoutDuplication = %ld\n", indexWithoutDuplication);
        zeroBasedIndex -= indexWithoutDuplication * numDuplications;
        for (int j = 0; j < N; ++j) {
            if (! isUsed[j]) {
                if (indexWithoutDuplication == 0) {
                    printf("%d\n", j + 1);
                    isUsed[j] = true;
                    break;
                }
                --indexWithoutDuplication;
            }
        }
    }
    return 0;
}
