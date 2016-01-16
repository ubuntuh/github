// とりあえず、例の入力程度なら、総当たり的な方法で答えが得られそうなので、総当たり的かつ雑な方法で実装し、submit してみた。
// ごく少数、序盤の 8 個のテストで Accepted を得たが、他は、Time Limit Exceeded、Runtime Error、Wrong Answer がバラバラに混ざった結果であった。
// なお、N が 1 であるテストにのみ正常に出力するプログラムを submit してみたところ、subtask1_* の 1, 2, 5, 6 のみ Accepted であった。他は Wrong Answer と Runtime Error が半々くらいであった。要するに、元のプログラムも、N が 1 の場合の正解がほとんどだった。
#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;

int N; // [1, 10000]
int x[10000];
int y[10000];
int xMin = INT_MAX;
int xMax = INT_MIN;
int yMin = INT_MAX;
int yMax = INT_MIN;

int getManhattanDistance(int a, int b, int c, int d) {
    return abs(a - c) + abs(b - d);
}

int main() {
    scanf("%d\n", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x[i], &y[i]);
        xMin = min(xMin, x[i]);
        xMax = max(xMax, x[i]);
        yMin = min(yMin, y[i]);
        yMax = max(yMax, y[i]);
    }
    // printf("%d %d %d %d\n", xMin, xMax, yMin, yMax);
    if (N == 1) {
        printf("%d %d\n", x[0], y[0]);
        return 0;
    }
    for (int py = yMin; py <= yMax; ++py) {
        for (int px = xMin; px <= xMax; ++px) {
            bool isFound = true;
            int distance = getManhattanDistance(px, py, x[0], y[0]);
            for (int i = 1; i < N; ++i) {
                if (getManhattanDistance(px, py, x[i], y[i]) != distance) {
                    isFound = false;
                    break;
                }
            }
            if (isFound) {
                printf("%d %d\n", px, py);
                goto label;
            }
        }
    }
    label:;
    return 0;
}
