#include <cstdio>
#include <vector>
using namespace std;

long n;
long W;
vector<long> v;
vector<long> w;

long valueFirst() {
    // 価値が大きいもの優先。
    vector<long> v2(v.size());
    copy(v.begin(), v.end(), v2.begin());
    vector<long> w2(w.size());
    copy(w.begin(), w.end(), w2.begin());
    for (int i = 2; i <= n; i++) {
        int j = i;
        while (2 <= j && v2[j - 1] < v2[j]) {
            swap(v2[j - 1], v2[j]);
            swap(w2[j - 1], w2[j]);
            j--;
        }
    }
    for (int i = 1; i <= n; i++) {
        // printf("Sorted = %ld, %ld\n", v2[i], w2[i]);
    }
    long freeWeight = W;
    long totalValue = 0;
    while (true) {
        int newItem = -1;
        for (int i = 1; i <= n; i++) {
            if (v2[i] == -1) continue;
            if (w2[i] <= freeWeight) {
                if (newItem == -1) {
                    newItem = i;
                } else {
                    if (v2[newItem] < v2[i]) {
                        newItem = i;
                    }
                }
            }
        }
        if (newItem == -1) {
            break;
        } else {
            totalValue += v2[newItem];
            freeWeight -= w2[newItem];
            v2[newItem] = -1;
            w2[newItem] = -1;
        }
    }
    return totalValue;
}

long rec(long i, long j) {
    int res;
    if (i == n + 1) {
        res = 0;
    } else if (j < w[i]) {
        res = rec(i + 1, j);
    } else {
        res = max(rec(i + 1, j),
                  rec(i + 1, j - w[i]) + v[i]);
    }
    return res;
}

int main() {
    scanf("%ld %ld\n", &n, &W);
    printf("n, W = %ld, %ld\n", n, W);
    v.resize(n + 1);
    w.resize(W + 1);
    for (int i = 1; i <= n; i++) {
        long value;
        long weight;
        scanf("%ld %ld\n", &value, &weight);
        v[i] = value;
        w[i] = weight;
    }
    for (int i = 1; i <= n; i++) {
        printf("v, w = %ld, %ld\n", v[i], w[i]);
    }
    printf("valueFirst = %ld\n", valueFirst());
    printf("rec = %ld\n", rec(1, W));
    return 0;
}
