#include <cstdio>

int n; // n <= 10,000
int* S;
int q; // q <=    500
bool isIn(int value) {
    for (int i = 0; i <= n - 1; ++i) {
        if (S[i] == value) {
            return true;
        }
    }
    return false;
}
int main() {
    scanf("%d\n", &n);
    S = new int[n];
    for (int i = 0; i <= n - 1; ++i) {
        scanf("%d", &S[i]);
    }
    scanf("%d\n", &q);
    int t;
    int answer = 0;
    for (int i = 0; i <= q - 1; ++i) {
        scanf("%d", &t);
        if (isIn(t)) ++answer;
    }
    printf("%d\n", answer);
    delete[] S;
    return 0;
}
