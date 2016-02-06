#include <cstdio>
#include <cstring>

int N;
char maxName[21];
int maxPopulation;
int totalPopulation;

int main() {
    scanf("%d\n", &N);
    for (int i = 0; i <= N - 1; ++i) {
        char* name;
        int population;
        scanf("%s %d\n", name, &population);
        totalPopulation += population;
        if (population > maxPopulation) {
            maxPopulation = population;
            strcpy(maxName, name);
        }
    }
    int half = totalPopulation / 2;
    if (maxPopulation > half) {
        printf("%s\n", maxName);
    } else {
        printf("atcoder\n");
    }
    return 0;
}
