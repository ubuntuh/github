// Accepted.
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    int oa, ab, bc;
    scanf("%d%d%d", &oa, &ab, &bc);
    int sum = oa + ab + bc;
    int longest = max(oa, max(ab, bc));
    int left = sum - longest;
    double area = M_PI * sum * sum;
    if (left < longest) {
        area -= M_PI * (longest - left) * (longest - left);
    }
    printf("%f\n", area);
    return 0;
}
