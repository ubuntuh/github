#include <cstdio>
int N, K;
int chars[100000];
int useChar(int indexWithoutDuplication) {
    for (int i = 0; i <= N - 1; ++i) {
        if (chars[i] != -1) {
            if (indexWithoutDuplication == 0) {
                int temp = chars[i];
                chars[i] = -1;
                return temp;
            } else --indexWithoutDuplication;
        }
    }
    return -1;
}
void printChars(void) {
    printf("    chars = {");
    for (int i = 0; i <= N - 1; ++i) {
        if (chars[i] != -1) printf(" %d", chars[i]);
    }
    printf("}\n");
}
long getFactorial(int a) {
    if (a == 0 || a == 1) return 1;
    return a * getFactorial(a - 1);
}
int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; ++i) {
        chars[i - 1] = i;
    }
    long zeroBasedIndex = getFactorial(N) / K - 1;
    int indexWithoutDuplication, ch;
    int Ni = N;
    for (int i = 1; i <= N; ++i) {
        printf("                   = %ld of [0..%ld]\n", zeroBasedIndex, getFactorial(Ni) - 1);
        printf("    indexWithoutDuplication = %ld / %d!\n", zeroBasedIndex, Ni - 1);
        printf("                            = %ld / %ld\n", zeroBasedIndex, getFactorial(Ni - 1));
        indexWithoutDuplication = zeroBasedIndex / getFactorial(Ni - 1);
        printf("                            = %d of [0..%d]\n", indexWithoutDuplication, Ni - 1);
        printChars();
        ch = useChar(indexWithoutDuplication);
        printf("%d\n", ch);
        printf("    zeroBasedIndex = %ld %% %d!\n", zeroBasedIndex, Ni - 1);
        printf("                   = %ld %% %ld\n", zeroBasedIndex, getFactorial(Ni - 1));
        zeroBasedIndex = zeroBasedIndex % getFactorial(Ni - 1);
        --Ni;
    }
    return 0;
}
