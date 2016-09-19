#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
const int INF = 0x7fffffff;
int num[MAXN], leftMax[MAXN], rightMin[MAXN], ans[MAXN], N, cnt = 0;

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &num[i]);
	}
	leftMax[0] = 0;
	for(int i = 1; i < N; ++i){
		leftMax[i] = max(leftMax[i-1], num[i-1]);
	}
	rightMin[N-1] = INF;
	for(int i = N-2; i >=0; --i){
		rightMin[i] = min(rightMin[i+1], num[i+1]);
	}
	for(int i = 0; i < N; ++i){
		if(leftMax[i] < num[i] && rightMin[i] > num[i]){
			ans[cnt++] = num[i];
		}
	}
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; ++i){
		printf("%d", ans[i]);
		if(i != cnt-1) printf(" ");
	}
	printf("\n");
	return 0;
}