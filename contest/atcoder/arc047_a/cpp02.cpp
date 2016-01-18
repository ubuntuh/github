// Accepted.
#include <cstdio>

int N; // [1, 10000]
int L; // [1, 10000]
char c;

int main() {
    scanf("%d %d\n", &N, &L);
    int numOpens = 0;
    for (int i = 1; i <= N; i++) {
       scanf("%c", &c);
       if (c == '+') {
           ++numOpens;
       }
    }
    // printf("numOpens = %d\n", numOpens);
    int numCloses = N - numOpens;
    // printf("numCloses = %d\n", numCloses);
    int distance = numOpens - numCloses;
    // printf("distance = %d\n", distance);
    int numCrashes = distance / L;
    printf("%d\n", numCrashes);
    return 0;
}
