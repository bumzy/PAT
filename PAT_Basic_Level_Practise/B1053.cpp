#include <cstdio>
using namespace std;

const int MAXN = 1000 + 10;
int N, D;
double e;
double num[MAXN];

int main(){
	int empty = 0, possible = 0;
	scanf("%d%lf%d", &N, &e, &D);
	for(int i = 0; i < N; ++i){
		int K;
		scanf("%d", &K);
		for(int j = 0; j < K; ++j){
			scanf("%lf", &num[j]);
		}
		int cnt = 0;
		for(int j = 0; j < K; ++j){
			if(num[j] < e)
				++cnt;
		}
		if(cnt > K/2){
			if(K <= D) possible++;
			else empty++;
		}
	}
	printf("%.1lf%% %.1lf%%", possible * 100.0 / N , empty * 100.0 / N);
	return 0;
}