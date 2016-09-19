#include <cstdio>
using namespace std;

const int MAXN = 100000 + 10;
int N;
double num[MAXN];

int main(){
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		scanf("%lf", &num[i]);
	}
	double ans = 0;
	for(int i = 1; i <= N; ++i){
		ans += num[i] * i * (N+1-i);
	}
	printf("%.2lf", ans);
	return 0;
}