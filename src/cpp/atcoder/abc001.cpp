#include <iostream>
using namespace std;

int main() {
    int h1; // ある時刻の積雪深
    int h2; // その 1 時間前の積雪深
    cin >> h1 >> h2;
    int h3; // この 1 時間の積雪深差
    h3 = h1 - h2;
    cout << h3 << endl;
    return 0;
}

