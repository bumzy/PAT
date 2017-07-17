#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int n1, m1, n2, m2, k;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    if (n1 * m2 > n2 * m1) {
        swap(n1, n2);
        swap(m1, m2);
    }
    int min_i = ceil((double)n1 / m1 * k);
    int max_i = floor((double)n2 / m2 * k);
    bool first = true;
    for (int i = min_i; i <= max_i; ++i) {
        if (k % i != 0) {
            if (!first) {
                printf(" ");
            } else {
                first = false;
            }
            printf("%d/%d", i, k);
        }
    }
    printf("\n");
    return 0;
}
