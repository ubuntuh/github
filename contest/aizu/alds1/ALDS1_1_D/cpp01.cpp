#include <cstdio>

int main(int argc, char** argv) {
    // 実験的に、総当たり的に実装します。計算量は悪く、O(n^2) です。
    // Status: Time Limit Exceeded (35/40)
    int *data, i, j, n;
    int localMax, max, profit;
    std::scanf("%d", &n);
    data = new int[n];
    for (i = 0; i < n; i++) {
        std::scanf("%d", &data[i]);
    }
    max = -1000000000;
    for (i = 0; i < n - 1; i++) {
        localMax = -1000000000;
        for (j = i + 1; j < n; j++) {
            profit = data[j] - data[i];
            if (localMax < profit) {
                localMax = profit;
            }
        }
        if (max < localMax) {
            max = localMax;
        }
    }
    std::printf("%d\n", max);
    delete[] data;
    return 0;
}
