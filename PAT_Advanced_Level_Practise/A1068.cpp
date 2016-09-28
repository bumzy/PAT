#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 10000 + 10;
const int MAXM = 100 + 10;
int N, M;
int w[MAXN], dp[MAXM] = {0};
bool choice[MAXN][MAXM], flag[MAXN];

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; ++i){
		scanf("%d", &w[i]);
	}
	sort(w+1, w+N+1, greater<int>());
	for(int i = 1; i <= N; ++i){
		for(int v = M; v >= w[i]; --v){
			if(dp[v] <= dp[v - w[i]] + w[i]){
				dp[v] = dp[v - w[i]] + w[i];
				choice[i][v] = true;
			}else{
				choice[i][v] = false;
			}
		}
	}
	if(dp[M] != M) printf("No Solution");
	else{
		int k = N, num = 0, v = M;
		while(k >= 1){
			if(choice[k][v] == true){
				flag[k] = true;
				v -= w[k];
				++num;
			}else{
				flag[k] = false;
			}
			--k;
		}
		for(int i = N; i >= 1; --i){
			if(flag[i] == true){
				printf("%d", w[i]);
				--num;
				if(num > 0) printf(" ");
			}
		}
	}
	return 0;
}