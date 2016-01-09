// Wrong Answer.
#include <cstdio>

int main() {
    int N, K, *ss;
    int maxlen = 0;
    scanf("%d %d", &N, &K);
    ss = new int[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &ss[i]);
    }
    int head = 0;
    int product = 1;
    for (int i = 0; i < N; i++) {
        if (ss[i] == 0) {
            maxlen = N;
            break;
        }
        product *= ss[i];
        // printf("product = %d; head = %d\n", product, head);
        while (K < product) {
            if (i == head) {
                head = i + 1;
                product = 1;
                goto continue0;
            }
            product /= ss[head];
            head++;
            // printf("Head moved; product = %d; head = %d\n", product, head);
        }
        if (product <= K) {
            int len = i - head + 1;
            if (maxlen < len) maxlen = len;
            // printf("product <= K; len = %d; maxlen = %d\n", len, maxlen);
        }
        continue0:;
    }
    printf("%d\n", maxlen);
}
