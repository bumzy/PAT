#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 1000000 + 10;
bool num[MAXN] = {false};
int prime[MAXN], pNum = 0;

void findPrime(int n){
	for(int i = 2; i < MAXN; ++i){
		if(num[i] == false){
			num[i] = true;
			prime[pNum++] = i;
			if(i > n) break;
			for(int j = i+i; j < MAXN; j += i){
				num[j] = true;
			}
		}
	}
}

struct factor{
	int p, cnt;
} fac[10];

int main(){
	int n;
	scanf("%d", &n);
	findPrime(n);
	if(n == 1) printf("1=1");
	else{
		printf("%d=", n);
		int facN = 0;
		int sqr = round(sqrt(1.0 * n));
		for(int i = 0; i < pNum; ++i){
			if(n % prime[i] == 0){
				fac[facN].p = prime[i];
				fac[facN].cnt = 0;
				while(n % prime[i] == 0){
					++fac[facN].cnt;
					n /= prime[i];
				}
				++facN;
			}
			if(n == 1) break;
		}
		if(n != 1){
			fac[facN].p = n;
			fac[facN++].cnt = 1;
		}
		for(int i = 0; i < facN; ++i){
			if(i > 0) printf("*");
			printf("%d", fac[i].p);
			if(fac[i].cnt > 1){
				printf("^%d", fac[i].cnt);
			}
		}
	}
	return 0;
}