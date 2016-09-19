#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int coin[MAXN];
int N, M;

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i){
		scanf("%d", &coin[i]);
	}
	sort(coin, coin + N);
	int i = 0, j = N - 1;
	while(i < j){
		if(coin[i] + coin[j] == M) break;
		else if(coin[i] + coin[j] < M) ++i;
		else --j;
	}
	if(i < j){
		printf("%d %d", coin[i], coin[j]);
	}else{
		printf("No Solution");
	}
	return 0;
}