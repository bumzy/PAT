#include <cstdio>
using namespace std;

const int MAXN = 10000000 + 10;
int prime[MAXN], count = 0;
bool num[MAXN] = {false};
int N;

void findPrime(){
	for(int i = 2; i <= N; ++i){
		if(num[i] == false){
			prime[count++] = i;
			//if(count == n) break;
			for(int j = i+i; j <= N; j += i){
				num[j] = true;
			}
		}
	}
}

int main(){
	scanf("%d", &N);
	findPrime();
	int cnt = 0;
	for(int i = 0; i < count; ++i){
		if(prime[i+1] - prime[i] == 2){
			//printf("%d %d\n", prime[i+1], prime[i]);
			++cnt;
		}
	}
	printf("%d\n", cnt);
	return 0;
}