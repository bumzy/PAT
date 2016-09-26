#include <cstdio>

const int MAXN = 100000 + 10;
int count[110] = {0};

int main(){
	int N;
	scanf("%d", &N);
	while(N--){
		int score;
		scanf("%d", &score);
		++count[score];
	}
	int K;
	scanf("%d", &K);
	while(K--){
		int score;
		scanf("%d", &score);
		printf("%d", count[score]);
		if(K != 0)
			printf(" ");
	}
	return 0;
}