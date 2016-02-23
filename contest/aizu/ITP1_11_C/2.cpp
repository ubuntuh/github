// Accepted.
#include <cstdio>
int dice[] = {-1, 10, 20, 30, 40, 50, 60}, dice2[7];
int labels[7], labels2[7];
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
void update() {
    for (int i = 1; i <= 6; ++i) {
        dice[i] = dice2[i];
    }
}
void N() {
    dice2[1] = dice[2];
    dice2[2] = dice[6];
    dice2[3] = rotate(dice[3], 1);
    dice2[4] = rotate(dice[4], 3);
    dice2[5] = rotate(dice[1], 2);
    dice2[6] = rotate(dice[5], 2);
    update();
}
void S() {
    dice2[1] = rotate(dice[5], 2);
    dice2[2] = dice[1];
    dice2[3] = rotate(dice[3], 3);
    dice2[4] = rotate(dice[4], 1);
    dice2[5] = rotate(dice[6], 2);
    dice2[6] = dice[2];
    update();
}
void W() {
    dice2[1] = rotate(dice[3], 3);
    dice2[2] = rotate(dice[2], 3);
    dice2[3] = rotate(dice[6], 3);
    dice2[4] = rotate(dice[1], 3);
    dice2[5] = rotate(dice[5], 1);
    dice2[6] = rotate(dice[4], 3);
    update();
}
void E() {
    dice2[1] = rotate(dice[4], 1);
    dice2[2] = rotate(dice[2], 1);
    dice2[3] = rotate(dice[1], 1);
    dice2[4] = rotate(dice[6], 1);
    dice2[5] = rotate(dice[5], 3);
    dice2[6] = rotate(dice[3], 1);
    update();
}
int main() {
    for (int i = 1; i <= 6; ++i) {
        scanf("%d", &labels[i]);
    }
    for (int i = 1; i <= 6; ++i) {
        scanf("%d", &labels2[i]);
    }
    int jomenLabel, zenmenLabel;
    jomenLabel = labels2[1];
    zenmenLabel = labels2[2];
    int jomen, zenmen;
    for (int j = 1; j <= 6; ++j) {
        if (labels[j] == jomenLabel) jomen = j;
    }
    for (int j = 1; j <= 6; ++j) {
        if (labels[j] == zenmenLabel) zenmen = j;
    }
    // printf("jomen, zenmen = %d, %d\n", jomen, zenmen);
    while (1) {
        if (dice[1] / 10 == jomen) break;
        N();
        if (dice[1] / 10 == jomen) break;
        N();
        if (dice[1] / 10 == jomen) break;
        N();
        if (dice[1] / 10 == jomen) break;
        W();
        if (dice[1] / 10 == jomen) break;
        W(); W();
        break;
    }
    while (1) {
        if (dice[2] / 10 == zenmen) break;
        N(); W(); S();
        if (dice[2] / 10 == zenmen) break;
        N(); W(); S();
        if (dice[2] / 10 == zenmen) break;
        N(); W(); S();
        break;
    }
    // printDice();
    if (labels[dice[3] / 10] == labels2[3]
        && labels[dice[4] / 10] == labels2[4]
        && labels[dice[5] / 10] == labels2[5]
        && labels[dice[6] / 10] == labels2[6]) {
        puts("Yes");
    } else puts("No");
    return 0;
}
