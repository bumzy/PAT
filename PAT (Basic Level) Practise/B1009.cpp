#include <cstdio>
int main(){
	char ans[90][90];
	int num = 0;
	while(scanf("%s", ans[num]) != EOF){
		++num;
	}
	for(int i = num - 1; i >= 0; --i){
		if(i != num - 1) printf(" ");
		printf("%s", ans[i]);
	}
	return 0;
}