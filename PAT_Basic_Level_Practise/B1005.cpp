#include <cstdio>

bool valid[110] = {false};
int count[110] = {0};

void callatz(int n){
	//++count[n];
	while(n != 1){
		if(n <= 100)
			++count[n];
		if(n % 2 == 0){
			n /= 2;
		}else{
			n = (3*n+1)/2;
		}
	}
}

int main(){
	int K;
	scanf("%d", &K);
	for(int i = 0; i < K; ++i){
		int num;
		scanf("%d", &num);
		valid[num] = true;
		callatz(num);
	}
	bool first = true;
	for(int i = 100; i > 1; --i){
		if(valid[i] && count[i] == 1){
			if(first == true){
				printf("%d", i);
				first = false;
			}
			else{
				printf(" %d", i);
			}
		}
	}
	return 0;
}