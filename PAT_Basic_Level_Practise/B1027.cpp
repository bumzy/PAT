#include <cstdio>

int main(){
	int n;
	char c[4];
	scanf("%d%s", &n, c);
	int bottom = -1;
	int remain = 0;
	while(n >= 0){
		remain = n;
		bottom += 2;
		n -= (bottom > 1 ? bottom*2 : 1);
	}
	bottom -= 2;
	int blank = 0;
	int fill = bottom;
	for(int i = 0; i < bottom; ++i){
		for(int j = 0; j < blank; ++j){
			printf(" ");
		}
		for(int j = 0; j < fill; ++j){
			printf("%s", c);
		}
		if(i < bottom / 2){
			fill -= 2;
			++blank;
		}else{
			fill += 2;
			--blank;
		}
		printf("\n");
	}
	printf("%d", remain);
	//printf("%d", bottom);
	return 0;
}