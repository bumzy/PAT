#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1010;
char str[MAXN];
bool dp[MAXN][MAXN] = {false};

int main(){
	gets(str);
	int len = strlen(str), ans = 1;
	for(int i = 0; i < len; ++i){
		dp[i][i] = true;
		if(i < len -1 && str[i] == str[i+1]){
			dp[i][i+1] = true;
			ans = 2;
		}
	}
	for(int L = 3; L <= len; ++L){
		for(int i = 0; i+L-1 < len; ++i){
			int j = i+L-1;
			if(str[i] == str[j] && dp[i+1][j-1] == true){
				dp[i][j] = true;
				ans = L;
			}
		}
	}
	printf("%d", ans);
	return 0;
}