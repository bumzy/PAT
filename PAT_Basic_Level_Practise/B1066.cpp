/*************************************************************************
	> File Name: B1066.cpp
	> Author: bumzy
	> Mail: bumzy@gmail.com
	> Created Time: 2017年07月30日 星期日 17时38分01秒
 ************************************************************************/

#include <stdio.h>
using namespace std;

const int MAXN = 500 + 10;
int matrix[MAXN][MAXN];

int main(void) {
    int m, n, low, high, replace;
    scanf("%d%d%d%d%d", &m, &n, &low, &high, &replace);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] >= low && matrix[i][j] <= high) {
                matrix[i][j] = replace;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%03d", matrix[i][j]);
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
