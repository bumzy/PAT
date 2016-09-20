#include <cstdio>
using namespace std;

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int sum = a + b;
	if(sum < 0){
		printf("-");
		sum = 0 - sum;
	}
	int len = 0;
	int num[10];
	if(sum == 0) num[len++] = 0;
	while(sum){
		num[len++] = sum % 10;
		sum /= 10;
	}
	for(int i = len - 1; i >=0; --i){
		printf("%d", num[i]);
		if(i > 0 && i % 3 == 0) printf(",");
	}
	return 0;
}