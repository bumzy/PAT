#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int coin[MAXN] = {0};
int N, M;

int binary_search(int left, int right, int x){
	int mid;
	while(left <= right){
		mid = (left + right) / 2;
		if(coin[mid] == x) return mid;
		if(coin[mid] > x){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	return -1;
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i){
		scanf("%d", &coin[i]);
	}
	sort(coin, coin + N);
	int i;
	for(i = 0; i < N; ++i){
		int j = binary_search(0, N, M-coin[i]);
		if(j != -1 && j != i){
			printf("%d %d", coin[i], coin[j]);
			return 0;
		}
	}
	if(i == N){
		printf("No Solution");
	}
	return 0;
}