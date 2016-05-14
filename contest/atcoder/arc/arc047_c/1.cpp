// 2016-01-18 Mon. Time Limit Exceeded.
// 最も素朴に、ありうる順列を具体的に全てメモリに展開し、N! / K 番目の要素を出力する。
// 設問に添付された sample_02.txt についてすら TLE である戦略であり、6 つのテストでのみ Accepted であった。Accepted でないものは TLE であった。
#include <cstdio>
#include <list>
using namespace std;

int N; // [1, 100000]
int K; // [1, 100000] and K <= N
typedef list<int> IntList;
typedef IntList::iterator IntListItr;
typedef list<IntList> IntListList;
typedef IntListList::iterator IntListListItr;

void print(IntList* intList) {
    for (IntListItr itr = intList->begin(); itr != intList->end(); ++itr) {
        printf("%d", *itr);
        if (itr != --intList->end()) {
            printf(" ");
        }
    }
}
void print(IntListList* intListList, long wordNum) {
    long i = 1;
    for (IntListListItr itr = intListList->begin(); itr != intListList->end(); ++itr) {
        if (i == wordNum) printf("->");
        printf("Word #%ld = ", i);
        IntList* intList = &(*itr);
        print(intList);
        printf("\n");
        i++;
    }
}
void getWords(IntListList* words, IntList* word, IntList* chars) {
    if (chars->empty()) {
        words->push_back(*word);
    }
    for (IntListItr itr = chars->begin(); itr != chars->end(); ++itr) {
        IntList nextChars;
        int ch = *itr;
        itr = chars->erase(itr);
        nextChars = *chars;
        itr = chars->insert(itr, ch);
        IntList nextWord;
        nextWord = *word;
        nextWord.push_back(ch);
        getWords(words, &nextWord, &nextChars);
    }
}
long getFactorial(long a) {
    if (a == 1) return 1;
    else        return a * getFactorial(a - 1);
}
int main() {
    scanf("%d %d", &N, &K);
    // printf("N, K = %d %d\n", N, K);
    int numChars = N;
    long numWords = getFactorial(numChars);
    // printf("numWords = %ld\n", numWords);
    long wordNum = numWords / K;
    // printf("wordNum = N! / K = %ld\n", wordNum);

    IntList chars;
    for (int i = 1; i <= numChars; i++) {
        chars.push_back(i);
    }
    IntListList words;
    IntList word;
    getWords(&words, &word, &chars);
    print(&words, wordNum);

    long wordNumTemp = 1;
    IntList *ansWord;
    for (IntListListItr itr = words.begin(); itr != words.end(); ++itr) {
        if (wordNumTemp == wordNum) {
            ansWord = &*itr;
        }
        ++wordNumTemp;
    }
    for (IntListItr itr = ansWord->begin(); itr != ansWord->end(); ++ itr) {
        printf("%d\n", *itr);
    }
    return 0;
}
