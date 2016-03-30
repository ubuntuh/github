#include <cstdio>
int n, S[100000 + 1], q, T[50000 + 1];
int search(int key) {
    int left = 1;
    int right = n;
    while (left <= right) {
        int center = left + (right - left) / 2;
        // printf("left, right, center = %d, %d, %d\n", left, right, center);
        if (key < S[center]) {
            right = center - 1;
        } else if (S[center] == key) {
            return center;
        } else {
            left = center + 1;
        }
    }
    return -1;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        scanf("%d", &T[i]);
    }
    int answer = 0;
    for (int i = 1; i <= q; ++i) {
        int result = search(T[i]);
        // printf("result = %d\n", result);
        if (result != -1) ++answer;
    }
    printf("%d\n", answer);
    return 0;
}
