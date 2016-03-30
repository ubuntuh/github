#include <cstdio>

#define DEBUG
#ifdef DEBUG
#define dprintf printf
#else
#define dprintf 1 ? (void) 0 : (void)
#endif

int main(int argc, char** argv) {
    int i, n, price, profit;
    bool isSearchingMin = true;
    int lastMin = 1000000001, lastMax = 0;
    int lastProfit = -1000000001;
    int min = 1000000001, max = 0;
    bool isStrictlyDecreasing = true;
    int lastPrice = 2000000000, maxSlope = -1000000000, slope;
    std::scanf("%d", &n);
    for (i = 0; i <= n; i++) {
        if (i == n) {
            price = -1000000000;
        } else {
            std::scanf("%d", &price);
        }
        dprintf("==== Processing Data #%d (%d).\n", i, price);
        if (isSearchingMin) {
            dprintf("Searching Min.\n");
            if (isStrictlyDecreasing) {
                slope = price - lastPrice;
                if (maxSlope < slope) {
                    maxSlope = slope;
                }
                lastPrice = price;
                if (min < price) {
                    isStrictlyDecreasing = false;
                }
            }
            if (price <= min) {
                min = price;
            } else {
                max = price;
                isSearchingMin = false;
            }
        } else {
            dprintf("Searching Max.\n");
            if (max <= price) {
                max = price;
            } else {
                if (lastMin <= min) {
                    if (lastMax < max) {
                        dprintf("lastMax %d -> %d\n", lastMax, max);
                        lastMax = max;
                        dprintf("lastProfit %d -> %d\n", lastProfit, lastMax - lastMin);
                        lastProfit = lastMax - lastMin;
                    }
                } else {
                    profit = max - min;
                    if (lastProfit < profit) {
                        lastMin = min;
                        lastMax = max;
                        dprintf("lastProfit %d -> %d\n", lastProfit, profit);
                        lastProfit = profit;
                    }
                }
                if (price < min) {
                    min = price;
                }
                max = 0;
                isSearchingMin = true;
            }
        }
        dprintf("lastMin, lastMax == %d, %d\n", lastMin, lastMax);
        dprintf("min, max == %d, %d\n", min, max);
    }
    dprintf("isStrictlyDecreasing == %d\n", isStrictlyDecreasing);
    if (isStrictlyDecreasing) {
        std::printf("%d\n", maxSlope);
    } else {
        std::printf("%d\n", lastProfit);
    }
    return 0;
}
