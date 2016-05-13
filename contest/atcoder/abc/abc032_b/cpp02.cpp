#include <cstdio>
#include <set>
#include <string>
using namespace std;

int main() {
    char s[300];
    string s1;
    int k;
    int answer;
    set<string> strings;
    scanf("%s\n", s);
    s1 = string(s);
    scanf("%d", &k);
    if (s1.length() < k) {
        answer = 0;
    } else {
        for (int i = 0; i <= s1.length() - k; i++) {
            string sub;
            sub = s1.substr(i, k);
            strings.insert(sub);
        }
        answer = strings.size();
    }
    printf("%d\n", answer);
}
