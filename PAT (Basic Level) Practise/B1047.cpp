#include <cstdio>

int count[1010] = {0};

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int team, person, score;
		scanf("%d-%d %d", &team, &person, &score);
		count[team] += score;
	}
	int max = 0, id;
	for(int i = 1; i <= 1000; ++i){
		if(count[i] > max){
			max = count[i];
			id = i;
		}
	}
	printf("%d %d", id, max);
	return 0;
}