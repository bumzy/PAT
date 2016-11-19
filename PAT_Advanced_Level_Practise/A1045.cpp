#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, L, hashTable[210];
int arr[10010], dp[10010];

int main(){
	for(int i = 0; i < 210; ++i)
		hashTable[i] = -1;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i){
		int x;
		scanf("%d", &x);
		hashTable[x] = i;
	}
	scanf("%d", &L);
	int num = 0;
	for(int i = 0; i < L; ++i){
		int x;
		scanf("%d", &x);
		if(hashTable[x] >= 0)
			arr[num++] = hashTable[x];
	}
	int ans = 0;
	for(int i = 0; i < num; ++i){
		dp[i] = 1;
		for(int j = 0; j < i; ++j){
			if(arr[j] <= arr[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}