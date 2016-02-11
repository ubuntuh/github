#include <cstdio>
int n;
bool cards[4][13];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        char suit;
        int rank;
        scanf(" %c %d", &suit, &rank);
        switch (suit) {
        case 'S': cards[0][rank - 1] = true; break;
        case 'H': cards[1][rank - 1] = true; break;
        case 'C': cards[2][rank - 1] = true; break;
        case 'D': cards[3][rank - 1] = true; break;            
        }
    }
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 13; ++j) {
            if (! cards[i - 1][j - 1]) {
                switch (i) {
                case 1: printf("S"); break;
                case 2: printf("H"); break;
                case 3: printf("C"); break;
                case 4: printf("D"); break;
                }
                printf(" %d\n", j);
            }
        }
    }
    return 0;
}
