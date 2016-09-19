#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int num[MAXN];

int main(){
	int N, p;
	scanf("%d%d", &N, &p);
	for(int i = 0; i < N; ++i){
		scanf("%d", &num[i]);
	}
	sort(num, num + N);
	int i = 0, j = 0, count = 1;
	while(i < N && j < N){
		while(j < N && num[j] <= (long long)num[i] * p){
			count = max(count, j - i + 1);
			++j;
		}
		++i;
	}
	printf("%d", count);
	return 0;
}