#include <cstdio>
using namespace std;

int main(){
	int T;
	int k = 0;
	scanf("%d", &T);
	while(T--){
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		long long a1, a2, b1, b2, c1, c2;
		a1 = a%10;
		a2 = a/10;
		b1 = b%10;
		b2 = b/10;
		c1 = c%10;
		c2 = c/10;
		if((a2 + b2 + (a1 + b1)/10 > c2) || (a2 + b2 + (a1 + b1)/10 == c2 && (a1 + b1)%10 > c1)){
			printf("Case #%d: true\n", ++k);
		}else{
			printf("Case #%d: false\n", ++k);
		}
	}
	return 0;
}