#include <cstdio>
#include <algorithm>
using namespace std;

long long num[100010];

int main(){
	int N;
	long long p;
	int ans = 0;
	scanf("%d%lld", &N, &p);
	for(int i = 0; i < N; ++i){
		scanf("%lld", &num[i]);
	}
	sort(num, num+N);
	int i = 0, j = 0;
	while(i < N && j < N){
		while(j < N && num[j] <= num[i] * p){
			ans = max(ans, j-i+1);
			++j;
		}
		++i;
	}
	printf("%d", ans);
	return 0;
}