#include <cstdio>
#include <iostream>
#include <list>
using namespace std;

class Block {
public:
    int start;
    int end;
    Block(int start, int end) {
        this->start = start - start % 5;
        int end2 = 1440 - end;
        int end3 = 1440 - (end2 - end2 % 5);
        this->end = end3;
    }
};
bool compare(Block& obj1, Block& obj2) {
    return obj1.start <= obj2.start;
}
bool merge(Block& obj1, Block& obj2) {
    if (obj1.end < obj2.start) {
        return false;
    }
    if (obj1.end < obj2.end) {
        obj1.end = obj2.end;
    }
    return true;
}
int getMinute(int hour, int minute) {
    return hour * 60 + minute;
}
void getHourAndMinute(int minute, int* hour, int* newMinute) {
    *hour = minute / 60;
    *newMinute = minute % 60;
}
int main() {
    int n;
    cin >> n;
    list<Block> blocks;
    for (int i = 0; i < n; i++) {
        int startHour, startMinute;
        int endHour, endMinute;
        scanf("%02d%02d-%02d%02d", &startHour, &startMinute, &endHour, &endMinute);
        int start, end;
        start = getMinute(startHour, startMinute);
        end = getMinute(endHour, endMinute);
        Block block(start, end);
        blocks.push_back(block);
    }
    blocks.sort(compare);
    list<Block>::iterator itr;
    itr = blocks.begin();
    Block *prev = &(*itr);
    ++itr;
    while(itr != blocks.end()) {
        bool result;
        result = merge(*prev, *itr);
        if (result) {
            itr = blocks.erase(itr);
        } else {
            prev = &(*itr);
            ++itr;
        }
    }
    itr = blocks.begin();
    while(itr != blocks.end()) {
        int startHour, startMinute;
        int endHour, endMinute;
        getHourAndMinute(itr->start, &startHour, &startMinute);
        getHourAndMinute(itr->end, &endHour, &endMinute);
        printf("%02d%02d-%02d%02d\n", startHour, startMinute, endHour, endMinute);
        ++itr;
    }
}

