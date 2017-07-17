#include <stdio.h>
using namespace std;

const int MAX_NUM = 100 + 10;
int weight[MAX_NUM];
int ans[MAX_NUM];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &ans[i]);
    }
    for (int i = 0; i < n; ++i) {
        int score = 0;
        for (int j = 0; j < m; ++j) {
            int x;
            scanf("%d", &x);
            if (x == ans[j]) {
                score += weight[j];
            }
        }
        printf("%d\n", score);
    }
    return 0;
}
