#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 10000 + 10;
int N, m, n;
int num[MAXN];
int outPut[MAXN][MAXN];

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &num[i]);
	}
	if(N == 1){
		printf("%d", num[0]);
		return 0;
	}
	sort(num, num+N, greater<int>());
	int sqr = sqrt(N*1.0);
	for(int i = sqr; i >= 1; --i){
		if(N%i == 0){
			n = i;
			m = N/i;
			break;
		}
	}
	int U = 1, B = m, L = 1, R = n;
	int i = 1, j = 1;
	int idx = 0;
	while(idx < N){
		while(idx < N && j < R){
			outPut[i][j] = num[idx++];
			++j;
		}
		while(idx < N && i < B){
			outPut[i][j] = num[idx++];
			++i;
		}
		while(idx < N && j > L){
			outPut[i][j] = num[idx++];
			--j;
		}
		while(idx < N && i > U){
			outPut[i][j] = num[idx++];
			--i;
		}
		++U; --B; ++L; --R;
		++i; ++j;
		if(idx == N-1){
			outPut[i][j] = num[idx++];
		}
	}
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			printf("%d", outPut[i][j]);
			if(j != n) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}