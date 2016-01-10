// 積を int 型の変数で計算し、具体的には、long product とすべきところを int product としていて、そのまま submit して Wrong Answer になり、悩みました。
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
    long product = 1;
    for (int i = 0; i < N; i++) {
        if (ss[i] == 0) {
            maxlen = N;
            break;
        }
        product *= ss[i];
        while (K < product) {
            if (i == head) {
                head = i + 1;
                product = 1;
                goto continue0;
            }
            product /= ss[head];
            head++;
        }
        if (product <= K) {
            int len = i - head + 1;
            if (maxlen < len) maxlen = len;
        }
        continue0:;
    }
    printf("%d\n", maxlen);
}
