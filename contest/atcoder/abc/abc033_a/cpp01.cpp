#include <cstdio>

int N;

int main() {
    scanf("%d", &N);
    if (N % 1111)
        printf("DIFFERENT\n");
    else
        printf("SAME\n");
    return 0;
}
