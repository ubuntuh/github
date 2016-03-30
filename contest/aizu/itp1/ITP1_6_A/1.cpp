#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int* a = new int[n];
    int i;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &a[i - 1]);
    }
    while (1 <= --i) {
        printf("%d", a[i - 1]);
        if (i != 1) printf(" ");
        else printf("\n");
    }
    delete[] a;
    return 0;
}
