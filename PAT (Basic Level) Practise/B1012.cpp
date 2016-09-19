#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 1000 + 10;
const int EPSILON = 1e-15;
int main(){
	int digit[MAXN];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &digit[i]);
	}
	int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
	double a4 = 0.0;
	int flag = 1;
	int cnt[2] = {0};
	for(int i = 0; i < n; ++i){
		int d = digit[i];
		switch(d % 5){
			case 0:
				if(d % 2 == 0) a1 += d;
				break;
			case 1:
				a2 += flag * d;
				flag = -flag;
				++cnt[0];
				break;
			case 2:
				++a3;
				break;
			case 3:
				a4 += d;
				++cnt[1];
				break;
			case 4:
				if(d > a5) a5 = d;
				break;
		}
	}
	if(a1 != 0) printf("%d ", a1);
	else printf("N ");
	if(cnt[0] != 0) printf("%d ", a2);
	else printf("N ");
	if(a3 != 0) printf("%d ", a3);
	else printf("N ");
	if(cnt[1] > 0) printf("%.1f ", a4/cnt[1]);
	else printf("N ");
	if(a5 != 0) printf("%d", a5);
	else printf("N");
	return 0;
}