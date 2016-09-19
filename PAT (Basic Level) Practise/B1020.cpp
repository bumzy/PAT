#include <cstdio>
#include <algorithm>
using namespace std;

struct Mooncake{
	double store, sell, price;
} cake[1010];

bool cmp(const Mooncake &m1, const Mooncake &m2){
	return m1.price > m2.price;
}

int main(){
	int N, D;
	scanf("%d%d", &N, &D);
	for(int i = 0; i < N; ++i){
		scanf("%lf", &cake[i].store);
	}
	for(int i = 0; i < N; ++i){
		scanf("%lf", &cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;
	}
	sort(cake, cake + N, cmp);
	double ans = 0.0;
	for(int i = 0; i < N; ++i){
		if(cake[i].store <= D){
			D -= cake[i].store;
			ans += cake[i].sell;
		}else{
			ans += cake[i].price * D;
			break;
		}
	}
	printf("%.2f", ans);
	return 0;
}