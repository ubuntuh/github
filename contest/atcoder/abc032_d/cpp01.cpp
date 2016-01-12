#include <cstdio>
#include <list>
using namespace std;

int main() {
    int N; // [1, 200]
    int W; // [1, 1,000,000,000]
    scanf("%d %d\n", &N, &W);
    int values[201];
    int weights[201];
    for (int i = 1; i <= N; i++) {
        scanf("%d %d\n", &values[i], &weights[i]);
    }
    printf("N, W = %d, %d\n", N, W);
    for (int i = 1; i <= N; i++) {
        printf("value, weight = %d, %d\n", values[i], weights[i]);
    }
    bool isN30 = false;
    if (N <= 30) isN30 = true;
    bool isW1000 = true;
    bool isV1000 = true;
    for (int i = 1; i <= N; i++) {
        if (1000 < weights[i]) isW1000 = false;
        if (1000 < values[i]) isV1000 = false;
    }
    printf("%d %d %d\n", isN30, isW1000, isV1000);
    if (true || isW1000) {
        long maxValues[N + 1][W + 1];
        // m[i][j] は、i 番目までの品物について重量 j 以下での価値の最大値である。
        for (int j = 0; j <= W; j++) {
            maxValues[0][j] = 0;
        }
        // 品物を 1 つずつ見ていく。
        for (int i = 1; i <= N; i++) {
            // 重量制限を走査していく。
            for (int j = 0; j <= W; j++) {
                bool isAdd;
                long keeped = maxValues[i - 1][j];
                long gained = -1;
                if (j < weights[i]) {
                    // 品物 i だけで重量制限を突破する場合。
                    // この場合、品物 i の重量を差し引いたセルは存在せず参照できないために、特別扱いする必要がある。
                    isAdd = false;
                } else {
                    // 品物 i - 1 までで重量 j - weights[i] 以下での価値の最大値を参照する。
                    long oldValue = maxValues[i - 1][j - weights[i]];
                    // この品物、品物 i を追加した場合の価値を計算する。
                    gained = oldValue + values[i];
                    // 追加できて追加した場合の最大価値と追加できるかにかかわらず追加しなかった場合での最大価値を比較する。
                    if (gained <= keeped) isAdd = false;
                    else                  isAdd = true;
                }
                if (isAdd) maxValues[i][j] = gained;
                else       maxValues[i][j] = keeped;
                printf("%ld, ", maxValues[i][j]);
            }
            printf("\n");
        }
        printf("%ld\n", maxValues[N][W]);
    }
    return 0;
}
