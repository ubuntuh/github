// Accepted.
#include <cstdio>
int dice[] = {-1, 10, 20, 30, 40, 50, 60}, dice2[7];
int labels[101][7];
void printDice() {
    for (int i = 1; i <= 6; ++i) {
        printf(" %d", dice[i]);
    }
    puts("");
}
void printLabels(int index) {
    printf("labels[%d] =", index);
    for (int i = 1; i <= 6; ++i) {
        printf(" %d", labels[index][i]);
    }
    puts("");
}
bool isSameLabelSet(int index1, int index2) {
    int left[7], right[7];
    for (int i = 1; i <= 6; ++i) {
        left[i] = labels[index1][i];
        right[i] = labels[index2][i];
    }
    for (int i = 1; i <= 6; ++i) {
        bool found = false;
        for (int j = 1; j <= 6; ++j) {
            if (left[i] == right[j]) {
                found = true;
                right[j] = -1;
                break;
            }
        }
        if (! found) {
            // printf("not found - %d, %d, %d\n", index1, index2, i);
            return false;
        }
    }
    return true;
}
void initDice(void) {
    for (int i = 1; i <= 6; ++i) dice[i] = i * 10;
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
    int n;
    scanf("%d", &n);
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= 6; ++b) {
            scanf("%d", &labels[a][b]);
        }
    }
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {
            if (a == b) continue;
            initDice();
            if (! isSameLabelSet(a, b)) continue;
            int jomenLabel, zenmenLabel;
            jomenLabel = labels[b][1];
            zenmenLabel = labels[b][2];
            int jomen, zenmen;
            for (int j = 1; j <= 6; ++j) {
                if (labels[a][j] == jomenLabel) jomen = j;
            }
            for (int j = 1; j <= 6; ++j) {
                if (labels[a][j] == zenmenLabel) zenmen = j;
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
            if (labels[a][dice[3] / 10] == labels[b][3]
                && labels[a][dice[4] / 10] == labels[b][4]
                && labels[a][dice[5] / 10] == labels[b][5]
                && labels[a][dice[6] / 10] == labels[b][6]) {
                // printf("a, b = %d, %d\n", a, b);
                // printLabels(a);
                // printLabels(b);
                // printDice();
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}
