#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 200 + 10;
const int MAXL = 10000 + 10;
int N, M, L, A[MAXN], B[MAXL], dp[MAXN][MAXL];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i) {
		scanf("%d", &A[i]);
		dp[i][0] = 0;
	}
	scanf("%d", &L);
	for (int i = 1; i <= L; ++i) {
		scanf("%d", &B[i]);
		dp[0][i] = 0;
	}
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= L; ++j) {
			if (A[i] == B[j]) {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + 1;
			} else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	printf("%d\n", dp[M][L]);
	return 0;
}