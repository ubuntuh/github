// Accepted.
#include <cstdio>
int Deg, Dis;
int main() {
    scanf("%d%d", &Deg, &Dis);
    double Deg2 = Deg / 10.;
    const char *fukou;
    if (Deg2 < 11.25) fukou = "N";
    else if (Deg2 < 33.75) fukou = "NNE";
    else if (Deg2 < 56.25) fukou = "NE";
    else if (Deg2 < 78.75) fukou = "ENE";
    else if (Deg2 < 101.25) fukou = "E";
    else if (Deg2 < 123.75) fukou = "ESE";
    else if (Deg2 < 146.25) fukou = "SE";
    else if (Deg2 < 168.75) fukou = "SSE";
    else if (Deg2 < 191.25) fukou = "S";
    else if (Deg2 < 213.75) fukou = "SSW";
    else if (Deg2 < 236.25) fukou = "SW";
    else if (Deg2 < 258.75) fukou = "WSW";
    else if (Deg2 < 281.25) fukou = "W";
    else if (Deg2 < 303.75) fukou = "WNW";
    else if (Deg2 < 326.25) fukou = "NW";
    else if (Deg2 < 348.75) fukou = "NNW";
    else fukou = "N";
    double fusoku = Dis / 60.;
    int furyoku;
    if (fusoku < 0.25) furyoku = 0;
    else if (fusoku < 1.55) furyoku = 1;
    else if (fusoku < 3.35) furyoku = 2;
    else if (fusoku < 5.45) furyoku = 3;
    else if (fusoku < 7.95) furyoku = 4;
    else if (fusoku < 10.75) furyoku = 5;
    else if (fusoku < 13.85) furyoku = 6;
    else if (fusoku < 17.15) furyoku = 7;
    else if (fusoku < 20.75) furyoku = 8;
    else if (fusoku < 24.45) furyoku = 9;
    else if (fusoku < 28.45) furyoku = 10;
    else if (fusoku < 32.65) furyoku = 11;
    else furyoku = 12;
    if (furyoku == 0) fukou = "C";
    printf("%s %d\n", fukou, furyoku);
}
