// Accepted.
#include <cstdio>
int Deg; // 0 <= Deg < 3,600。90 度なら 900、137.5 度なら 1375。
int Dis; // 0 <= Dis < 12,000。単位は m。
const char *fukouStrings[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
double fusokuValues[] = {0.25, 1.55, 3.35, 5.45, 7.95, 10.75, 13.85, 17.15, 20.75, 24.45, 28.45, 32.65, 12000 / 60.};
int main() {
    scanf("%d%d", &Deg, &Dis);
    // 風向を判定する境界は 11.25 度、33.75 度など、22.5 度間隔である。実際に与えられる Deg は、112 や 113 なので、11.25 度未満は 11.3 度未満と考えてもいい。風向を整数 0...15 で表したい。0..112 -> 0、113..337 -> 1、...。
    int fukou = (Deg + 112) / 225 % 16;
    double fusoku = Dis / 60.;
    int furyoku;
    for (furyoku = 0;; ++furyoku) {
        if (fusoku < fusokuValues[furyoku]) break;
    }
    if (furyoku) printf("%s %d\n", fukouStrings[fukou], furyoku);
    else printf("%s %d\n", "C", furyoku);
    return 0;
}
