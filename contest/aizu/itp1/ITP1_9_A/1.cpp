#include <cctype>
#include <cstdio>
#include <cstring>
char W[11], s[1001];
int answer;
void getUppercase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        ++i;
    }
}
int main() {
    scanf("%s", W);
    getUppercase(W);
    while (1) {
        scanf("%s", s);
        if (! strcmp(s, "END_OF_TEXT")) break;
        getUppercase(s);
        if (! strcmp(s, W)) ++answer;
    }
    printf("%d\n", answer);
    return 0;
}
