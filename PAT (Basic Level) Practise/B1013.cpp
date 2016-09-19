#include <cstdio>
using namespace std;

const int MAXN = 1000000 + 10;
bool num[MAXN] = {false};
int prime[MAXN], count = 0;

void findPrime(int n){
	for(int i = 2; i < MAXN; ++i){
		if(num[i] == false){
			prime[count++] = i;
			if(count >= n) break;
			for(int j = i+i; j < MAXN; j += i){
				num[j] = true;
			}
		}
	}
}

int main(){
	int N, M, cnt = 0;
	scanf("%d%d", &M, &N);
	findPrime(N);
	for(int i = M; i <= N; ++i){
		printf("%d", prime[i - 1]);
		++cnt;
		if(cnt % 10 != 0 && i < N) printf(" ");
		else printf("\n");
	}
	return 0;
}