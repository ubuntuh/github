#include <cstdio>
#include <cstring>

int N;
char maxName[21];
int maxPopulation;
int totalPopulation;

int main() {
    scanf("%d\n", &N);
    for (int i = 0; i <= N - 1; ++i) {
        char name[21];
        // この行を、char name[21]; ではなく char* name; としていたところ、Wrong Answer となり、問題の原因がどこにあるのか探すのに多く時間がかかった。
        // あるいは、この行に問題があったというより、char* name に対して下で strcpy をしようとしていたのが間違いなのかもしれない。
        // よくわかっていない。
        // しかし、ローカルでは動いていたようだった。そしてリモートのテストは公開されていない。
        // The additional arguments should point to alreadly allocated objects ....
        
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
