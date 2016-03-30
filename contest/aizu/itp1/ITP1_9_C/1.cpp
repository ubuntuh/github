#include <cstdio>
#include <cstring>
int n; // n <= 1,000
char taro[101], hanako[101];
int taroScore, hanakoScore;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %s", taro, hanako);
        int value = strcmp(taro, hanako);
        if (0 < value) {
            taroScore += 3;
        } else if (value < 0) {
            hanakoScore += 3;
        } else {
            ++taroScore;
            ++hanakoScore;
        }
    }
    printf("%d %d\n", taroScore, hanakoScore);
    return 0;
}
