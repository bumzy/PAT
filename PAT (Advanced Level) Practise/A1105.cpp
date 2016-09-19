#include <cstdio>
#include <algorithm>
#include <cmath>
#include <functional>
using namespace std;

const int MAXN = 10000 + 10;
int N, m, n;
int num[MAXN];
int matrix[MAXN][MAXN] = {0};

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &num[i]);
	}
	if(N == 1){
		printf("%d", num[0]);
		return 0;
	}
	sort(num, num + N, greater<int>());
	int sqr = floor(sqrt(N*1.0));
	for(n = sqr; n >= 1; --n){
		if(N % n == 0) break;
	}
	m = N / n;
	int i = 1, j = 1, now = 0;
	int U = 1, D = m, L = 1, R = n;
	while(now < N){
		while(now < N && j < R){
			matrix[i][j] = num[now++];
			++j;
		}
		while(now < N && i < D){
			matrix[i][j] = num[now++];
			++i;
		}
		while(now < N && j > L){
			matrix[i][j] = num[now++];
			--j;
		}
		while(now < N && i > U){
			matrix[i][j] = num[now++];
			--i;
		}
		++U; --D; ++L; --R;
		++i; ++j;
		if(now == N-1){
			matrix[i][j] = num[now++];
		}
	}
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			printf("%d", matrix[i][j]);
			if(j < n) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}