#include <cstdio>
#include <cstring>

const char DIGIT[10][8] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
	char str[110];
	scanf("%s", str);
	int len = strlen(str);
	int sum = 0;
	for(int i = 0; i < len; ++i){
		sum += str[i] - '0';
	}
	len = 0;
	int ans[10];
	if(sum == 0) ans[len++] = 0;
	while(sum){
		ans[len++] = sum % 10;
		sum /= 10;
	}
	for(int i = len - 1; i >= 0; --i){
		if( i != len - 1) printf(" ");
		printf("%s", DIGIT[ans[i]]);
	}
	return 0;
}