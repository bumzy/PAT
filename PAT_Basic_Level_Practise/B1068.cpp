/*************************************************************************
	> File Name: B1068.cpp
	> Author: bumzy
	> Mail: bumzy@gmail.com
	> Created Time: 2017年07月30日 星期日 21时31分14秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

const int MAXN = 1000 + 10;
int matrix[MAXN][MAXN];
const int step[8][2] = {-1, -1,
                        -1, 0,
                        -1, 1,
                        0, -1,
                        0, 1,
                        1, -1,
                        1, 0,
                        1, 1};

int main() {
    int m, n, tol;
    unordered_map<int, int> M;
    scanf("%d%d%d", &m, &n, &tol);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
            M[matrix[i][j]]++;
        }
    }
    vector<pair<int, int>> result;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool flag = true;
            for (int k = 0; k < 8; ++k) {
                int x = i + step[k][0];
                int y = j + step[k][1];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (abs(matrix[x][y] - matrix[i][j]) <= tol) {
                        flag = false;
                        break;
                    } 
                }
            }
            if (flag == true && M[matrix[i][j]] == 1) {
                result.push_back(make_pair(i, j));
            }
        }
    }
    if (result.size() == 0) {
        printf("Not Exist\n");
    } else if (result.size() == 1) {
        int x = result[0].first + 1;
        int y = result[0].second + 1;
        printf("(%d, %d): %d\n", y, x, matrix[x - 1][y - 1]);
    } else {
        printf("Not Unique\n");
    }
    return 0;
}
