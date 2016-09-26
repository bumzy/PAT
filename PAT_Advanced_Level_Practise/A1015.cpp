#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int num[110], cnt = 0;

bool isPrime(int n){
	if(n <= 1) return false;
	int sqr = round(sqrt(1.0 * n));
	for(int i = 2; i <= sqr; ++i){
		if(n%i == 0) return false;
	}
	return true;
}

int main(){
	int N, D;
	while(scanf("%d", &N) != EOF && N > 0){
		scanf("%d", &D);
		if(!isPrime(N)){
			printf("No\n");
		}else{
			cnt = 0;
			do{
				num[cnt++] = N % D;
				N /= D;
			}while(N != 0);
			for(int i = 0; i < cnt; ++i){
				N = N * D + num[i];
			}
			if(isPrime(N))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}