#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10000 + 10;
int N, K, rank[MAXN] = {0};
bool isPrime[MAXN], isChecked[MAXN] = {false};

void findPrime(){
	memset(isPrime, true, sizeof(isPrime));
	for(int i = 2; i < MAXN; ++i){
		for(int j = i + i; j < MAXN; j += i){
			isPrime[j] = false;
		}
	}
}

int main(){
	findPrime();
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int id;
		scanf("%d", &id);
		rank[id] = i + 1;
	}
	scanf("%d", &K);
	for(int i = 0; i < K; ++i){
		int id;
		scanf("%d", &id);
		if(rank[id] == 0){
			printf("%04d: Are you kidding?\n", id);
		}else if(isChecked[id]){
			printf("%04d: Checked\n", id);
		}else{
			if(rank[id] == 1){
				printf("%04d: Mystery Award\n", id);
			}else if(isPrime[rank[id]]){
				printf("%04d: Minion\n", id);
			}else{
				printf("%04d: Chocolate\n", id);
			}
			isChecked[id] = true;
		}
	}
	return 0;
}