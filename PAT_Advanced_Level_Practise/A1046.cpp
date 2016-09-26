#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

int dis[MAXN] = {0};
int A[MAXN] = {0};
int N, M, sum = 0;

int main(){
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		scanf("%d", &A[i]);
		sum += A[i];
		dis[i] = sum;
	}
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		if(a > b) swap(a, b);
		if(a == b){
			printf("0\n");
			continue;
		}
		int tmp = dis[b-1] - dis[a-1];
		printf("%d\n", min(tmp, sum - tmp));
		/**
		int shortest = 0;
		int cnt = b - a + 1;
		if(cnt * 2 < N){
			for(int j = a; j < b; ++j){
				shortest += dis[j];
			}
		}else{
			for(int j = 1; j < a; ++j){
				shortest += dis[j];
			}
			for(int j = b; j <= N; ++j){
				shortest += dis[j];
			}
		}
		if(shortest * 2 > sum){
			shortest = sum - shortest;
		}
		printf("%d", shortest);
		if(i != M - 1) printf("\n");
		**/
	}
	return 0;
}