#include <cstdio>

const int MAXN = 100000 + 10;
int sum[MAXN] = {0};
int S, Snear = 0x7fffffff, N;

int upper_bound(int left, int right, int x){
	int mid;
	while(left < right){
		mid = (left + right) / 2;
		if(sum[mid] > x){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	return left;
}

int main(){
	scanf("%d%d", &N, &S);
	for(int i = 1; i <= N; ++i){
		scanf("%d", &sum[i]);
		sum[i] += sum[i-1];
	}
	for(int i = 1; i <= N; ++i){
		int j = upper_bound(i, N+1, sum[i-1] + S);
		if(sum[j-1] - sum[i-1] == S){
			Snear = S;
			break;
		}else if(j <= N && sum[j] - sum[i-1] < Snear){
			Snear = sum[j] - sum[i-1];
		}
	}
	for(int i = 1; i <= N; ++i){
		int j = upper_bound(i, N+1, sum[i-1] + Snear);
		if(sum[j-1] - sum[i-1] == Snear){
			printf("%d-%d\n", i, j-1);
		}
	}
	return 0;
}