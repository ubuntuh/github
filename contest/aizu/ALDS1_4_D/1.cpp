// Time Limit Exceeded.
// テキストで紹介されている、計算量が大きすぎる素朴なプログラム。O(Pn)。
// 入力が小さい testcase #34 までは Accepted。
#include <cstdio>
int n, k, w[100001];
int getSum() {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += w[i];
    }
    return sum;
}
// O(n).
int getNumItemsFromLoad(int P) {
    int numItems = 1;
    for (int truckNo = 1; truckNo <= k; ++truckNo) {
        int sum = 0;
        while (sum + w[numItems] <= P) {
            if (n < numItems) break;
            // printf("    #%d: %d += %d\n", truckNo, sum, w[numItems]);
            sum += w[numItems];
            ++numItems;
        }
    }
    return numItems - 1;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
    int sum = getSum();
    for (int P = 0; P <= sum; ++P) {
        int numItems = getNumItemsFromLoad(P);
        // printf("P, numItems = %d, %d\n", P, numItems);
        if (n == numItems) {
            printf("%d\n", P);
            return 0;
        }
    }
    return 0;
}
