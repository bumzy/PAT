#include <stdio.h>
#include <algorithm>
using namespace std;

static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int n1, m1, n2, m2, k;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    if (n1 * m2 > n2 * m1) {
        swap(n1, n2);
        swap(m1, m2);
    }
    int num = 1;
    while (n1 * k >= m1 * num) {
        num++;
    }
    bool first = true;
    for (; num * m2 < n2 * k; ++num) {
        if (gcd(num, k) == 1) {
            if (!first) {
                printf(" ");
            } else {
                first = false;
            }
            printf("%d/%d", num, k);
        }
    }
    printf("\n");
    return 0;
}
