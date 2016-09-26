#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
long long N, p;
long long num[MAXN];

int upper_bound(long long left, long long right, long long x){
	long long mid;
	while(left < right){
		mid = (left + right) / 2;
		if(num[mid] > x){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	return left;
}

int main(){
	scanf("%lld%lld", &N, &p);
	for(int i = 0; i < N; ++i){
		scanf("%lld", &num[i]);
	}
	sort(num, num + N);
	int ans = 0;
	for(int i = 0; i < N; ++i){
		int j = upper_bound(i+1, N, num[i]*p) - 1;
		ans = max(ans, j - i + 1);
	}
	printf("%d", ans);
	return 0;
}