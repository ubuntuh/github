#include <cstdio>
int N, K;
int chars[100000];
int useChar(int index) {
    for (int i = 0; i <= N - 1; ++i) {
        if (chars[i] != -1) {
            if (index == 1) {
                int temp = chars[i];
                chars[i] = -1;
                return temp;
            } else --index;
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
    long X = getFactorial(N) / K - 1;
    int index, ch;
    int Ni = N;
    for (int i = 1; i <= N; ++i) {
        printf("      = %ld of %ld\n", X, getFactorial(Ni) - 1);
        printf("    index = %ld / %d! + 1\n", X, Ni - 1);
        printf("          = %ld / %ld + 1\n", X, getFactorial(Ni - 1));
        index = X / getFactorial(Ni - 1) + 1;
        printf("          = %d of %d\n", index, Ni);
        printChars();
        ch = useChar(index);
        printf("%d\n", ch);
        printf("    X = %ld %% %d!\n", X, Ni - 1);
        printf("      = %ld %% %ld\n", X, getFactorial(Ni - 1));
        X = X % getFactorial(Ni - 1);
        --Ni;
    }
    return 0;
}
