#include <cstdio>
int dice[] = {-1, 10, 20, 30, 40, 50, 60}, dice2[7];
int labels[7];
void printDice() {
    for (int i = 1; i <= 6; ++i) {
        printf(" %d", dice[i]);
    }
    puts("");
}
int rotate(int state, int angle) {
    int oldAngle = state % 10;
    int newAngle = (oldAngle + angle) % 4;
    return state / 10 * 10 + newAngle;
}
void N() {
    dice2[1] = dice[2];
    dice2[2] = dice[6];
    dice2[3] = rotate(dice[3], 1);
    dice2[4] = rotate(dice[4], 3);
    dice2[5] = rotate(dice[1], 2);
    dice2[6] = rotate(dice[5], 2);
}
void S() {
    dice2[1] = rotate(dice[5], 2);
    dice2[2] = dice[1];
    dice2[3] = rotate(dice[3], 3);
    dice2[4] = rotate(dice[4], 1);
    dice2[5] = rotate(dice[6], 2);
    dice2[6] = dice[2];
}
void W() {
    dice2[1] = rotate(dice[3], 3);
    dice2[2] = rotate(dice[2], 3);
    dice2[3] = rotate(dice[6], 3);
    dice2[4] = rotate(dice[1], 3);
    dice2[5] = rotate(dice[5], 1);
    dice2[6] = rotate(dice[4], 3);
}
void E() {
    dice2[1] = rotate(dice[4], 1);
    dice2[2] = rotate(dice[2], 1);
    dice2[3] = rotate(dice[1], 1);
    dice2[4] = rotate(dice[6], 1);
    dice2[5] = rotate(dice[5], 3);
    dice2[6] = rotate(dice[3], 1);
}
int main() {
    for (int i = 1; i <= 6; ++i) {
        scanf("%d", &labels[i]);
    }
    char c;
    while (scanf(" %c", &c) != EOF) {
        if (c == '\n') break;
        switch (c) {
        case 'N': N(); break;
        case 'S': S(); break;
        case 'W': W(); break;
        case 'E': E(); break;
        }
        for (int i = 1; i <= 6; ++i) {
            dice[i] = dice2[i];
        }
        // printDice();
    }
    printf("%d\n", labels[dice[1] / 10]);
    return 0;
}
