#include <cstdio>

int ans[32] = {0};

int main(){
	int n, b;
	scanf("%d%d", &n, &b);
	int num = 0;
	do{
		ans[num++] = n % b;
		n /= b;
	}while(n != 0);
	bool flag = true;
	for(int i = 0; i <= num/2; ++i){
		if(ans[i] != ans[num - i - 1]){
			flag = false;
			break;
		}
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
	for(int i = num - 1; i >= 0; --i){
		if(i != num -1) printf(" ");
		printf("%d", ans[i]);
	}
}