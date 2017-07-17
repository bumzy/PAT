#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    int n1, m1, n2, m2, k;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    int min_i = ceil((double)n1 / m1 * k);
    int max_i = floor((double)n2 / m2 * k);
    for (int i = min_i; i <= max_i; ++i) {
        if (k % i != 0) {
            printf("%d/%d", i, k);
            if (i < max_i) {
                printf(" ");
            }
        }
    }
    printf("\n");
    return 0;
}
