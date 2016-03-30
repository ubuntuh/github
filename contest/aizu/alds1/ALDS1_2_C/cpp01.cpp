#include <algorithm>
#include <cstdio>

int N;
int* C_original;
int* C;
char* suits_original;
char* suits;

void copy() {
    for (int i = 0; i <= N - 1; ++i) {
        suits[i] = suits_original[i];
        C[i] = C_original[i];
    }
}

void BubbleSort(int* C, int N) {
    for (int i = 0; i <= N - 1; ++i) {
        for (int j = N - 1; j >= i; --j) {
            if (C[j] < C[j - 1]) {
                std::swap(C[j], C[j - 1]);
                std::swap(suits[j], suits[j - 1]);
            }
        }
    }
}

void SelectionSort(int* C, int N) {
    for (int i = 0; i <= N - 1; ++i) {
        int minj = i;
        for (int j = i; j <= N - 1; ++j) {
            if (C[j] < C[minj]) {
                minj = j;
            }
        }
        std::swap(C[i], C[minj]);
        std::swap(suits[i], suits[minj]);
    }
}

void printArray() {
    for (int i = 0; i <= N - 1; i++) {
        printf("%c%d", suits[i], C[i]);
        if(i <= N - 2) {
            printf(" ");
        }
    }
    printf("\n");
}

void printStable() {
    for (int i = 0; i <= N - 1; ++i) {
        int value = C_original[i];
        int j = 0, k = 0;
        while (1) {
            if (j >= N) {
                break;
            }
            while (C_original[j] != value) {
                ++j;
                if (j >= N) {
                    j = -1;
                    break;
                }
            }
            if (j == -1) break;
            while (C[k] != value) {
                ++k;
            }
            if (suits_original[j] != suits[k]) {
                printf("Not stable\n");
                return;
            }
            ++j;
            ++k;
        }
    }
    printf("Stable\n");
}

int main() {
    scanf("%d\n", &N);
    suits_original = new char[N];
    suits = new char[N];
    C_original = new int[N];
    C = new int[N];
    for (int i = 0; i <= N - 1; i++) {
        scanf(" %c", &suits_original[i]);
        scanf("%d", &C_original[i]);
    }
    copy();
    BubbleSort(C, N);
    printArray();
    printStable();
    copy();
    SelectionSort(C, N);
    printArray();
    printStable();
    return 0;
}
