#include <cstdio>

int count[10010] = {0};
int num[100010] = {0};

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &num[i]);
		++count[num[i]];
	}
	bool none = true;
	for(int i = 0; i < N; ++i){
		if(count[num[i]] == 1){
			none = false;
			printf("%d", num[i]);
			break;
		}
	}
	if(none) printf("None");
	return 0;
}