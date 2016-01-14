#include <cstdio>
#include <string>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    string s;
    if (a < b) {
        s = "a < b";
    } else if (a > b) {
        s = "a > b";
    } else { // a == b
        s = "a == b";
    }
    const char *sc = s.c_str();
    printf("%s\n", sc);
    return 0;
}
