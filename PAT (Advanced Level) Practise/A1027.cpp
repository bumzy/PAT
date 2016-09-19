#include <cstdio>

const char digit[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};

int main(){
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	//int sum = r*10000 + g*100 + b;
	//int ans[6];
	printf("#%c%c%c%c%c%c", digit[r/13], digit[r%13], digit[g/13], digit[g%13], digit[b/13], digit[b%13]);
	return 0;
}