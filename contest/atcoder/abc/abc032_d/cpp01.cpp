#include <cstdio>
#include <list>
#include <map>
using namespace std;

struct Node {
    int depth;
    Node *left;
    Node *right;
    long value;
    long weight;
};

int callCount = 0;
int cacheHit = 0;
bool useCache = true;
map<pair<int, long>, long> cache;

// 2 分木の節を与えられて子を追加します。
long addChildren(int N, int W, int* values, int* weights, Node* parent) {
    callCount++;
    int parentDepth = parent->depth;
    long freeWeight = W - parent->weight;
    if (useCache) {
        map<pair<int, long>, long>::iterator itr;
        itr = cache.find(make_pair(parentDepth, freeWeight));
        if (itr != cache.end()) {
            cacheHit++;
            return itr->second;
        }
    }
    // printf("%d addChildren() - depth = %d, weight = %ld\n", callCount, parentDepth, freeWeight);
    long result;
    if (parent->depth == N) {
        result = parent->value;
    } else {
        int depth = parent->depth + 1;
        Node left;
        left.depth = depth;
        left.value = parent->value;
        left.weight = parent->weight;
        parent->left = &left;
        long maxValueLeft = addChildren(N, W, values, weights, &left);
        Node right;
        right.depth = depth;
        right.value = parent->value + values[depth];
        right.weight = parent->weight + weights[depth];
        if (right.weight <= W) {
            parent->right = &right;
            long maxValueRight = addChildren(N, W, values, weights, &right);
            result = max(maxValueLeft, maxValueRight);
        } else {
            result = maxValueLeft;
        }
    }
    cache[make_pair(parentDepth, freeWeight)] = result;
    return result;
}

int main() {
    int N; // [1, 200]
    int W; // [1, 1,000,000,000]
    scanf("%d %d\n", &N, &W);
    int values[201];
    int weights[201];
    for (int i = 1; i <= N; i++) {
        scanf("%d %d\n", &values[i], &weights[i]);
    }
    bool isN30 = false;
    if (N <= 30) isN30 = true;
    bool isW1000 = true;
    bool isV1000 = true;
    for (int i = 1; i <= N; i++) {
        if (1000 < weights[i]) isW1000 = false;
        if (1000 < values[i]) isV1000 = false;
    }
    long vTotal = 0;
    if (isV1000) {
        for (int i = 1; i <= N; i++) {
            vTotal += values[i];
        }
    }
    if (false) {
        // Runtime Error. 33 点もらえる。
        long maxValues[N + 1][W + 1];
        // maxValues[i][j] は、i 番目までの品物について重量 j 以下での価値の最大値である。
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
            }
        }
        printf("%ld\n", maxValues[N][W]);
    } else if (true) {
        // ある重さにおける最大の価値と同様に、ある価値における最小の重さを考えることで、品物の価値の合計が低い場合には効率的に計算できるらしい。
        // ...動かない。
        printf("vTotal = %ld\n", vTotal);
        int TEMP = vTotal;
        long minWeights[N + 1][TEMP + 1];
        // minWeights[i][j] は、i 番目までの品物について価値 j 以下での重量の最小値である。
        for (int j = 0; j <= TEMP; j++) {
            minWeights[0][j] = 0;
        }
        // 品物を 1 つずつ見ていく。
        for (int i = 1; i <= N; i++) {
            // 価値制限を走査していく。
            for (int j = 0; j <= TEMP; j++) {
                bool isAdd;
                long keeped = minWeights[i - 1][j];
                long gained = -1;
                if (j < values[i]) {
                    // 品物 i だけで価値制限を突破する場合。
                    // この場合、品物 i の価値を差し引いたセルは存在せず参照できないために、特別扱いする必要がある。
                    isAdd = false;
                } else {
                    // 品物 i - 1 までで価値 j - values[i] 以下での重量の最小値を参照する。
                    long oldWeight = minWeights[i - 1][j - values[i]];
                    // この品物、品物 i を追加した場合の重量を計算する。
                    gained = oldWeight + weights[i];
                    // 追加できて追加した場合の最小重量と追加できるかにかかわらず追加しなかった場合での最小重量を比較する。
                    if (gained <= keeped) isAdd = false;
                    else                  isAdd = true;
                }
                if (isAdd) minWeights[i][j] = gained;
                else       minWeights[i][j] = keeped;
                printf("%ld, ", minWeights[i][j]);
            }
            printf("\n");
        }
        long maxValue = 0;
        long lastWeight = -1;
        for (int j = 1; j <= TEMP; j++) {
            if (minWeights[N][j] <= W) {
                long value = j;
                if (maxValue < value && minWeights[N][j] != lastWeight) {
                    maxValue = value;
                    lastWeight = minWeights[N][j];
                }
            }
        }
        printf("%ld\n", maxValue);
    } else {
        // Time Limit Exceeded. 半数ほど Accepted だが、3 種類のデータセット全てで失敗。
        // 改めて、再帰関数においてキャッシュを利用してみたら、Wrong Answer だが 34 点もらえた。
        // subtask01_5.txt で TLE -> AC。subtask01_*.txt という名前のものがデータセット 1 であるようである。
        Node tree;
        tree.depth = 0;
        tree.value = 0;
        tree.weight = 0;
        long maxValue = addChildren(N, W, values, weights, &tree);
        // printf("callCount = %d\n", callCount);
        if (useCache) {
            // printf("cacheHit = %d\n", cacheHit);
        }
        printf("%ld\n", maxValue);
    }
    return 0;
}
