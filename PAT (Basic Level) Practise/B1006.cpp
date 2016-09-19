#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int b = n / 100;
	int s = n / 10 % 10;
	int g = n % 10;
	for(int i = 3; i >= 1; --i){
		if(i == 3){
			for(int j = 0; j < b; ++j){
				printf("B");
			}
		}else if(i == 2){
			for(int j = 0; j < s; ++j){
				printf("S");
			}
		}else if(i == 1){
			for(int j = 1; j <= g; ++j){
				printf("%d", j);
			}
		}
	}
}