#include <cstdio>
int n, m, l;
int main() {
    scanf("%d %d %d", &n, &m, &l);
    int *A = new int[n * m];
    for (int ni = 0; ni <= n - 1; ++ni) {
        for (int mi = 0; mi <= m - 1; ++mi) {
            scanf("%d", &A[m * ni + mi]); 
        }
    }
    int *B = new int[m * l];
    for (int mi = 0; mi <= m - 1; ++mi) {
        for (int li = 0; li <= l - 1; ++li) {
            scanf("%d", &B[l * mi + li]);
        }
    }
    for (int ni = 0; ni <= n - 1; ++ni) {
        for (int li = 0; li <= l - 1; ++li) {
            long value = 0;
            for (int mi = 0; mi <= m - 1; ++mi) {
                value += A[m * ni + mi] * B[l * mi + li];
            }
            printf("%ld", value);
            if (li != l - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    delete[] A;
    delete[] B;
    return 0;
}
