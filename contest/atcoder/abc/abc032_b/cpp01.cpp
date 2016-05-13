#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main() {
    char s[300];
    string s1;
    int k;
    int answer;
    map<string, bool> strings;
    scanf("%s\n", s);
    s1 = string(s);
    scanf("%d", &k);
    if (s1.length() < k) {
        answer = 0;
    } else {
        for (int i = 0; i <= s1.length() - k; i++) {
            string sub;
            sub = s1.substr(i, k);
            strings[sub] = true;
        }
        answer = strings.size();
    }
    printf("%d\n", answer);
}
