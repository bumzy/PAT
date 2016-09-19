#include <cstdio>
#include <climits>

const int MAXN = 1000000 + 10;
//const long long INF = (1LL<<63)-1;
long long A[MAXN], B[MAXN];
int N, M;

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%lld", &A[i]);
	}
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		scanf("%lld", &B[i]);
	}
	A[N] = B[M] = LLONG_MAX;
	int i = 0, j = 0;
	int mid = 0;
	while(i <= N && j <= M){
		if(A[i] <= B[j]){
			if(mid == (N+M-1)/2){
				printf("%lld", A[i]);
				break;
			}
			++mid; ++i;
		}else{
			if(mid == (N+M-1)/2){
				printf("%lld", B[j]);
				break;
			}
			++mid; ++j;
		}
	}
	return 0;
}