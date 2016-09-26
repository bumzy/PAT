#include <cstdio>
#include <cstring>

const int MAXN = 40;
int ans[MAXN][MAXN];

int main(){
	char s[100];
	scanf("%s", s);
	int N = strlen(s);
	int n1 = (N + 2)/3, n3 = n1, n2 = N + 2 - n1 -n3;
	for(int i = 1; i <= n1; ++i){
		for(int j = 1; j <= n2; ++j){
			ans[i][j] = ' ';
		}
	} 
	int pos = 0;
	for(int i = 1; i <= n1; ++i){
		ans[i][1] = s[pos++];
	}
	for(int j = 2; j < n2; ++j){
		ans[n1][j] = s[pos++];
	}
	for(int i = n3; i >= 1; --i){
		ans[i][n2] = s[pos++];
	}
	for(int i = 1; i <= n1; ++i){
		for(int j = 1; j <= n2; ++j){
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}
}