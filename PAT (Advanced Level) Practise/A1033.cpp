#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 510;
const int INF = 0x7fffffff;

struct Station{
	double price, dis;
} sta[510];
double Cmax, D, Da;
int N;

bool cmp(const Station &s1, const Station &s2){
	return s1.dis < s2.dis;
}

int main(){
	scanf("%lf%lf%lf%d", &Cmax, &D, &Da, &N);
	for(int i = 0; i < N; ++i){
		scanf("%lf%lf", &sta[i].price, &sta[i].dis);
	}
	sta[N].price = 0;
	sta[N].dis = D;
	sort(sta, sta + N, cmp);
	if(sta[0].dis != 0){
		printf("The maximum travel distance = 0.00");
	}else{
		double ans = 0, nowTank = 0, MAX = Cmax * Da;
		int now = 0;
		while(now < N){
			int next = -1;
			double priceMin = INF;
			for(int i = now + 1; i <= N && sta[i].dis - sta[now].dis <= MAX; ++i){
				if(sta[i].price < priceMin){
					next = i;
					priceMin = sta[i].price;
				}
				if(priceMin < sta[now].price){
					break;
				}
			}
			if(next == -1) break;
			double need = (sta[next].dis - sta[now].dis) / Da;
			if(sta[next].price < sta[now].price){
				if(nowTank < need){
					ans += (need - nowTank) * sta[now].price;
					nowTank = 0;
				}else{
					nowTank -= need;
				}
			}else{
				ans += (Cmax - nowTank) * sta[now].price;
				nowTank = Cmax - need;
			}
			now = next;
		}
		if(now == N){
			printf("%.2lf", ans);
		}else{
			printf("The maximum travel distance = %0.2lf", sta[now].dis + MAX);
		}
	}
	return 0;
}