#include <cstdio>
using namespace std;

const int MAXN = 10000 + 10;
int N;
long long num[MAXN];
struct Node{
	long long sum;
	int begin, end;
	Node(int _begin=-1, int _end=-1, long long _sum=-1): begin(_begin), end(_end), sum(_sum) {}
};
Node dp[MAXN];

int main(){
	scanf("%d", &N);
	bool flag = true;
	for(int i = 0; i < N; ++i){
		scanf("%lld", &num[i]);
		if(num[i] >= 0) flag = false;
	}
	if(flag){
		printf("0 %lld %lld", num[0], num[N-1]);
		return 0;
	}
	dp[0] = Node(0, 0, num[0]);
	for(int i = 1; i < N; ++i){
		int begin, end;
		long long sum;
		if(num[i] <= dp[i-1].sum + num[i]){
			begin = dp[i-1].begin;
			end = i;
			sum = dp[i-1].sum + num[i];
			dp[i] = Node(begin, end, sum);
		}else{
			begin = end = i;
			sum = num[i];
			dp[i] = Node(begin, end, sum);
		}
	}
	int k = 0;
	for(int i = 1; i < N; ++i){
		if(dp[i].sum > dp[k].sum){
			k = i;
		}
	}
	printf("%lld %lld %lld", dp[k].sum, num[dp[k].begin], num[dp[k].end]);
	return 0;
}