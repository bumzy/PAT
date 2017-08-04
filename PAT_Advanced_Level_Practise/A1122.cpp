/*************************************************************************
	> File Name: A1122.cpp
	> Author: bumzy
	> Mail: bumzycm@gmail.com
	> Created Time: Fri 04 Aug 2017 11:02:16 AM CST
 ************************************************************************/

#include <stdio.h>
#include <vector>
using namespace std;

const int MAXN = 200 + 10;
bool matrix[MAXN][MAXN] = {false};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        matrix[v1][v2] = true;
        matrix[v2][v1] = true;
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        bool flag = true;
        int t;
        scanf("%d", &t);
        vector<int> cycle(t);
        for (int j = 0; j < t; ++j) {
            scanf("%d", &cycle[j]);
        }
        if (cycle[0] != cycle[t - 1] || t != n + 1) {
            flag = false;
        } else {
            int hash[MAXN] = {0};
            for (int j = 0; j < t - 1; ++j) {
                int u = cycle[j];
                int v = cycle[j + 1];
                if (hash[u] == 0) {
                    hash[u]++;
                } else {
                    flag = false;
                    break;
                }
                if (!matrix[u][v]) {
                    flag = false;
                    break;
                }
            }
            for (int j = 1; j <= n; ++j) {
                if (hash[j] != 1) {
                    flag = false;
                    break;
                }
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
