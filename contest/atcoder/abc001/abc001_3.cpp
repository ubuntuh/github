#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

double getFusokuFromFutei(double futei) {
    return futei / 60;
}
int getFuryokuFromFusoku(double fusoku) {
    int furyoku;
    if (fusoku < 0.25) {
        furyoku = 0;
    } else if (fusoku < 1.55) {
        furyoku = 1;
    } else if (fusoku < 3.35) {
        furyoku = 2;
    } else if (fusoku < 5.45) {
        furyoku = 3;
    } else if (fusoku < 7.95) {
        furyoku = 4;
    } else if (fusoku < 10.75) {
        furyoku = 5;
    } else if (fusoku < 13.85) {
        furyoku = 6;
    } else if (fusoku < 17.15) {
        furyoku = 7;
    } else if (fusoku < 20.75) {
        furyoku = 8;
    } else if (fusoku < 24.45) {
        furyoku = 9;
    } else if (fusoku < 28.45) {
        furyoku = 10;
    } else if (fusoku < 32.65) {
        furyoku = 11;
    } else {
        furyoku = 12;
    }
    return furyoku;
}
int getFuryokuFromFutei(double futei) {
    double fusoku = getFusokuFromFutei(futei);
    int furyoku = getFuryokuFromFusoku(fusoku);
    return furyoku;
}
string getFukouFromKakudo(double kakudo) {
    string fukou;
    if (kakudo < 11.25) {
        fukou = "N";
    } else if (kakudo < 33.75) {
        fukou = "NNE";
    } else if (kakudo < 56.25) {
        fukou = "NE";
    } else if (kakudo < 78.75) {
        fukou = "ENE";
    } else if (kakudo < 101.25) {
        fukou = "E";
    } else if (kakudo < 123.75) {
        fukou = "ESE";
    } else if (kakudo < 146.25) {
        fukou = "SE";
    } else if (kakudo < 168.75) {
        fukou = "SSE";
    } else if (kakudo < 191.25) {
        fukou = "S";
    } else if (kakudo < 213.75) {
        fukou = "SSW";
    } else if (kakudo < 236.25) {
        fukou = "SW";
    } else if (kakudo < 258.75) {
        fukou = "WSW";
    } else if (kakudo < 281.25) {
        fukou = "W";
    } else if (kakudo < 303.75) {
        fukou = "WNW";
    } else if (kakudo < 326.25) {
        fukou = "NW";
    } else if (kakudo < 348.75) {
        fukou = "NNW";
    } else if (kakudo < 360) {
        fukou = "N";
    } else {
        // illegal argument;
        fukou = "error";
    }
    return fukou;
}
string getFukouFromKakudoAndFuryoku(double kakudo, int furyoku) {
    string fukou;
    if (furyoku == 0) {
        fukou = "C";
    } else {
        fukou = getFukouFromKakudo(kakudo);
    }
    return fukou;
}
int main() {
    int deg; // 風向。137.5 度なら 1375。
    int dis; // 1 分間の風程。
    cin >> deg >> dis;
    int furyoku; // 風力
    furyoku = getFuryokuFromFutei(dis);
    string fukou; // 風向
    fukou = getFukouFromKakudoAndFuryoku(deg / (double)10, furyoku);
    printf("%s %d\n", fukou.c_str(), furyoku);
}

