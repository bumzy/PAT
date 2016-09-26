#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int coupon[MAXN], value[MAXN];
int NC, NP;

int main(){
	scanf("%d", &NC);
	for(int i = 0; i < NC; ++i){
		scanf("%d", &coupon[i]);
	}
	scanf("%d", &NP);
	for(int i = 0; i < NP; ++i){
		scanf("%d", &value[i]);
	}
	long long ans = 0;
	sort(coupon, coupon + NC);
	sort(value, value + NP);
	int cleft = 0, cright = NC-1;
	int pleft = 0, pright = NP-1;
	while(coupon[cright] > 0 && value[pright] > 0 && cright >= 0 && pright >= 0){
		ans += coupon[cright] * value[pright];
		--cright;
		--pright;
	}
	while(coupon[cleft] < 0 && value[pleft] < 0 && cleft <= NC-1 && pleft <= NP-1){
		ans += coupon[cleft] * value[pleft];
		++cleft;
		++pleft;
	}
	printf("%lld", ans);
	return 0;
}