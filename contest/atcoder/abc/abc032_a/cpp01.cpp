#include <cstdio>

int getGreatestCommonDivisor(int a, int b) {
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int getLeastCommonMultiple(int a, int b) {
    int gcd = getGreatestCommonDivisor(a, b);
    int lcm = a * b / gcd;
    return lcm;
}

int main() {
    int aoki, takahashi, n;
    int gcd, lcm;
    int answer;
    scanf("%d", &aoki);
    scanf("%d", &takahashi);
    scanf("%d", &n);
    // printf("aoki: %d\n", aoki);
    // printf("takahashi: %d\n", takahashi);
    gcd = getGreatestCommonDivisor(aoki, takahashi);
    // printf("gcd: %d\n", gcd);
    lcm = getLeastCommonMultiple(aoki, takahashi);
    // printf("lcm: %d\n", lcm);
    answer = ((n - 1) / lcm + 1) * lcm;
    printf("%d\n", answer);
}
