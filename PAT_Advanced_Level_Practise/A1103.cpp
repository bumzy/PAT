#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int N, K, P;
int maxFactor, maxSumFactor = -1;
vector<int> temp, ans;

void DFS(int factor, int nowK, int sum, int sumFactor){
	if(nowK == K && sum == N){
		/*if(sumFactor == maxSumFactor){
			bool flag = false;
			for(int i = 0; i < K; ++i){
				if(temp[i] > ans[i]){
					flag = true;
					break;
				}
			}
			if(flag) ans = temp;
		}else */
		if(sumFactor > maxSumFactor){
			maxSumFactor = sumFactor;
			ans = temp;
		}
		return;
	}
	if(factor <= 0 || nowK > K || sum > N) return;
	temp.push_back(factor);
	int t = pow(factor,P);
	DFS(factor, nowK+1, sum+t, sumFactor+factor);
	//DFS(factor-1, nowK+1, sum+t, sumFactor+factor);
	temp.pop_back();
	DFS(factor-1, nowK, sum, sumFactor);
}

int main(){
	scanf("%d%d%d", &N, &K, &P);
	maxFactor = floor(pow(1.0*N - K + 1, 1.0/P));
	DFS(maxFactor, 0, 0, 0);
	if(maxSumFactor == -1)
		printf("Impossible");
	else{
		printf("%d = ", N);
		for(int i = 0; i < K; ++i){
			if(i != 0) printf(" + ");
			printf("%d^%d", ans[i], P);
		}
	}
	return 0;
}