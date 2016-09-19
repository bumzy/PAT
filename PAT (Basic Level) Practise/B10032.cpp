#include <cstdio>
#include <cstring>
//#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int n;
int sum[MAXN];

int main(){
	scanf("%d", &n);
	memset(sum, 0, MAXN);
	for(int i = 0; i < n; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		sum[a] += b;
	}
	//sort(sum, sum + n, greater<int>());
	int idx, max = -1;
	for(int i = 1; i <= n; ++i){
		if(sum[i] > max){
			idx = i;
			max = sum[i];
		}
	}
	printf("%d %d", idx, max);
	return 0;
}