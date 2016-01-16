#include <cstdio>

int N; // [1, 10000]
int L; // [1, 10000]
char c;
int numTabs = 1;
int numCrashes = 0;

int main() {
    scanf("%d %d\n", &N, &L);
    for (int i = 1; i <= N; i++) {
       scanf("%c", &c);
       if (c == '-') {
           --numTabs;
       } else { // c == '+'
           ++numTabs;
           if (L < numTabs) {
               ++numCrashes;
               numTabs = 1;
           }
       }
    }
    printf("%d\n", numCrashes);
}
