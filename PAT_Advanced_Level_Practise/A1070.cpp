#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;
int N;
double D;
struct Mooncake{
	double amt, price, unit;
} mooncake[MAXN];

bool cmp(const Mooncake &m1, const Mooncake &m2){
	return m1.unit > m2.unit;
}

int main(){
	scanf("%d%lf", &N, &D);
	for(int i = 0; i < N; ++i){
		scanf("%lf", &mooncake[i].amt);
	};
	for(int i = 0; i < N; ++i){
		scanf("%lf", &mooncake[i].price);
		mooncake[i].unit = mooncake[i].price / mooncake[i].amt;
	}
	sort(mooncake, mooncake+N, cmp);
	int idx = 0;
	double ans = 0;
	while(D > 0){
		if(mooncake[idx].amt <= D){
			ans += mooncake[idx].price;
			D -= mooncake[idx].amt;
		}else{
			ans += mooncake[idx].unit * D;
			D = 0;
		}
		++idx;
	}
	printf("%.2lf", ans);
	return 0;
}