#include <cstdio>
using namespace std;

const int MAXN = 10000 + 10;
int a[MAXN], dp[MAXN];
int s[MAXN] = {0};

int main(){
	int N;
	scanf("%d", &N);
	bool flag = false;
	for(int i = 0; i < N; ++i){
		scanf("%d", &a[i]);
		if(a[i] >= 0) flag = true;
	}
	if(flag == false){
		printf("0 %d %d", a[0], a[N-1]);
		return 0;
	}
	dp[0] = a[0];
	for(int i = 1; i < N; ++i){
		if(dp[i-1] + a[i] >= a[i]){
			dp[i] = dp[i-1] + a[i];
			s[i] = s[i-1];
		}else{
			dp[i] = a[i];
			s[i] = i;
		}
	}
	int k = 0;
	for(int i = 1; i < N; ++i){
		if(dp[i] > dp[k]){
			k = i;
		}
	}
	printf("%d %d %d", dp[k], a[s[k]], a[k]);
	return 0;
}