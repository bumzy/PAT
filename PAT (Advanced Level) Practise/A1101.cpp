#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 100000 + 10;
int num[MAXN], ans[MAXN], leftMax[MAXN]={0}, rightMin[MAXN]={0}, N;

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &num[i]);
	}
	for(int i = 1; i < N; ++i){
		leftMax[i] = max(num[i-1], leftMax[i-1]);
	}
	rightMin[N-1] = INT_MAX;
	for(int i = N-2; i >= 0; --i){
		rightMin[i] = min(num[i+1], rightMin[i+1]);
	}

	int count = 0;
	for(int i = 0; i < N; ++i){
		if(num[i] > leftMax[i] && num[i] < rightMin[i]){
			ans[count++] = num[i];
		}
	}
	printf("%d\n", count);
	for(int i = 0; i < count; ++i){
		if(i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}