#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;

int N; // [1, 100000]
int x[100000];
int y[100000];
// ある点からのマンハッタン距離 r が等しい点を線で結ぶと、45 度転倒した正方形になる。これを半径 r の転倒正方形と呼ぼう。
// 正答である点 P からある半径で転倒正方形を描くと、入力される各点 (x_i, y_i) は全てそこに乗る。
// よって逆に、与えられた点を通る転倒正方形を探そう。
// 正答である転倒正方形の各辺を、次の 4 つの変数に求める。
int lowerRightLine = INT_MAX; // y =  x + lowerRightLine
int  upperLeftLine = INT_MIN; // y =  x +  upperLeftLine
int  lowerLeftLine = INT_MAX; // y = -x +  lowerLeftLine
int upperRightLine = INT_MIN; // y = -x + upperRightLine
// 各辺に乗った点の数を、次の 4 つの変数に求める。
int lrDots, ulDots, llDots, urDots;
// 各辺に置かれた点について、辺ごとに、座標の最小値と最大値を保持する。
int lrMinX, lrMaxX, lrMinY, lrMaxY;
int ulMinX, ulMaxX, ulMinY, ulMaxY;
int llMinX, llMaxX, llMinY, llMaxY;
int urMinX, urMaxX, urMinY, urMaxY;

int main() {
    scanf("%d\n", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x[i], &y[i]);
        // y = x + lowerRightLine
        // <=> lowerRightLine = y - x
        if (y[i] - x[i] < lowerRightLine) {
            // 右下の辺の位置が更新された場合である。
            lowerRightLine = y[i] - x[i];
            lrDots = 1;
            lrMinX = lrMaxX = x[i];
            lrMinY = lrMaxY = y[i];
        } else if (y[i] - x[i] == lowerRightLine) {
            // 与えられた点が右下の辺に乗っている場合である。
            ++lrDots;
            lrMinX = min(lrMinX, x[i]);
            lrMaxX = max(lrMaxX, x[i]);
            lrMinY = min(lrMinY, y[i]);
            lrMaxY = max(lrMaxY, y[i]);
        }
        if (upperLeftLine < y[i] - x[i]) {
            upperLeftLine = y[i] - x[i];
            ulDots = 1;
            ulMinX = ulMaxX = x[i];
            ulMinY = ulMaxY = y[i];
        } else if (upperLeftLine == y[i] - x[i]) {
            ++ulDots;
            ulMinX = min(ulMinX, x[i]);
            ulMaxX = max(ulMaxX, x[i]);
            ulMinY = min(ulMinY, y[i]);
            ulMaxY = max(ulMaxY, y[i]);
        }
        if (y[i] + x[i] < lowerLeftLine) {
            lowerLeftLine = y[i] + x[i];
            llDots = 1;
            llMinX = llMaxX = x[i];
            llMinY = llMaxY = y[i];
        } else if (y[i] + x[i] == lowerLeftLine) {
            ++llDots;
            llMinX = min(llMinX, x[i]);
            llMaxX = max(llMaxX, x[i]);
            llMinY = min(llMinY, y[i]);
            llMaxY = max(llMaxY, y[i]);
        }
        if (upperRightLine < y[i] + x[i]) {
            upperRightLine = y[i] + x[i];
            urDots = 1;
            urMinX = urMaxX = x[i];
            urMinY = urMaxY = y[i];
        } else if (upperRightLine == y[i] + x[i]) {
            ++urDots;
            urMinX = min(urMinX, x[i]);
            urMaxX = max(urMaxX, x[i]);
            urMinY = min(urMinY, y[i]);
            urMaxY = max(urMaxY, y[i]);
        }
    }
    if (upperLeftLine - lowerRightLine != upperRightLine - lowerLeftLine) {
        // 得られた 4 直線が、転倒した長方形あるいは線であって、まだ正方形ではない場合には、特別な処理をする。
        if (upperLeftLine - lowerRightLine < upperRightLine - lowerLeftLine) {
            // 転倒長方形が、右下と左上の間の方向に潰れている場合である。
            if ((lrDots == 1 && lrMaxX == llMaxX || lrMinX == urMaxX)
                || (lrDots == 2 && lrMinX == llMaxX && lrMaxX == urMaxX)) {
                // 右下の辺を動かすことができる場合である。
                lowerRightLine = upperLeftLine - (upperRightLine - lowerLeftLine);
            } else {
                // 右下の辺が動かせないならば、左上の辺が動かせるか、あるいは入力値が異常であると考え、入力異常はないものとして左上の辺を動かす。
                upperLeftLine = lowerRightLine + (upperRightLine - lowerLeftLine);
            }
        } else {
            if ((llDots == 1 && llMaxX == ulMinX || llMinX == lrMinX)
                || (llDots == 2 && llMinX == ulMinX && llMaxX == lrMinX)) {
                lowerLeftLine = upperRightLine - (upperLeftLine - lowerRightLine);
            } else {
                upperRightLine = lowerLeftLine + (upperLeftLine - lowerRightLine);
            }
        }
    }
    // 転倒正方形の中心を通る線を求める。
    int upwardLineMean = (lowerRightLine + upperLeftLine) / 2;
    int downwardLineMean = (lowerLeftLine + upperRightLine) / 2;
    // 転倒正方形の中心の座標を求める。
    int intersectX = (-upwardLineMean + downwardLineMean) / 2;
    int intersectY = (upwardLineMean + downwardLineMean) / 2;
    printf("%d %d\n", intersectX, intersectY);
    return 0;
}
