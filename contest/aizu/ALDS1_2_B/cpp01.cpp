#include <cstdio>

int N;
int* A;
int numSwap = 0;

void selectionSort(int* A, int N) {
    for (int i = 0; i <= N - 1; i++) {
        int minj = i;
        for (int j = i; j <= N - 1; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            int temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
            ++numSwap;
        }
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    scanf("%d\n", &N);
    A = new int[N];
    for (int i = 0; i <= N - 1; i++) {
        scanf("%d", &A[i]);
    }
    selectionSort(A, N);
    printArray(A, N);
    printf("%d\n", numSwap);
    return 0;
}
