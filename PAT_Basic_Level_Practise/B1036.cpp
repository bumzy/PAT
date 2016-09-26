#include <cstdio>

int main(){
	int n;
	char c[4];
	scanf("%d%s", &n, c);
	int h = (n + 1) / 2;
	for(int i = 0; i < h; ++i){
		if(i == 0 || i == h-1){
			for(int j = 0; j < n; ++j){
				printf("%s", c);
			}
		}else{
			printf("%s", c);
			for(int j = 1; j < n-1; ++j){
				printf(" ");
			}
			printf("%s", c);
		}
		printf("\n");
	}
	return 0;
}