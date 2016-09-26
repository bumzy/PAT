#include <cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int a[3] = {0};
	int b[3] = {0};
	int c[3] = {0};
	for(int i = 0; i < n; ++i){
		char x[2], y[2];
		scanf("%s%s", x, y);
		//printf("%c %c %d\n", x, y, i);
		if(x[0] == y[0]){
			++a[1];
		}else if((x[0] == 'C' && y[0] == 'J')||(x[0] == 'J' && y[0] == 'B')||(x[0] == 'B' && y[0] == 'C')){
			++a[0];
			if(x[0] == 'B'){
				++b[0];
			}else if(x[0] == 'C'){
				++b[1];
			}else if(x[0] == 'J'){
				++b[2];
			}
		}else{
			++a[2];
			if(y[0] == 'B'){
				++c[0];
			}else if(y[0] == 'C'){
				++c[1];
			}else if(y[0] == 'J'){
				++c[2];
			}
		}
	}
	for(int i = 0; i < 3; ++i){
		printf("%d", a[i]);
		if(i != 2) printf(" ");
	}
	printf("\n");
	for(int i = 0; i < 3; ++i){
		printf("%d", a[2-i]);
		if(i != 2) printf(" ");
	}
	printf("\n");

	int idx = -1, max = -1;
	for(int i = 2; i >= 0; --i){
		if(b[i] >= max){
			idx = i;
			max = b[i];
		}
	}
	if(idx == 0){
		printf("B ");
	}else if(idx == 1){
		printf("C ");
	}else if(idx == 2){
		printf("J ");
	}

	idx = -1;
	max = -1;
	for(int i = 2; i >= 0; --i){
		if(c[i] >= max){
			idx = i;
			max = c[i];
		}
	}
	if(idx == 0){
		printf("B");
	}else if(idx == 1){
		printf("C");
	}else if(idx == 2){
		printf("J");
	}
	return 0;
}