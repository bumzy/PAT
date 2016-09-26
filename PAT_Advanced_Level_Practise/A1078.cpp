#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN  = 100000 + 10;
bool hashTable[MAXN] = {false};
bool isPrime(int n){
	if(n <= 1) return false;
	int sqr = round(sqrt(1.0 * n));
	for(int i = 2; i <= sqr; ++i){
		if(n % i == 0) return false;
	}
	return true;
}

int main(){
	int TSize, N;
	scanf("%d%d", &TSize, &N);
	while(isPrime(TSize) == false){
		++TSize;
	}
	for(int i = 0; i< N; ++i){
		int num;
		scanf("%d", &num);
		int M = num % TSize;
		if(hashTable[M] == false){
			hashTable[M] = true;
			if(i != 0) printf(" ");
			printf("%d", M);
		}else{
			int step;
			for(step = 1; step < TSize; ++step){
				M = (num + step * step) % TSize;
				if(hashTable[M] == false){
					hashTable[M] = true;
					if(i != 0) printf(" ");
					printf("%d", M);
					break;
				}
			}
			if(step >= TSize){
				if(i != 0) printf(" ");
				printf("-");
			}
		}
	}
	return 0;
}