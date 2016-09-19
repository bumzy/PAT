#include <cstdio>

int main(){
	int N, ans = 0, a = 1;
	scanf("%d", &N);
	int left , now, right;
	while(N / a != 0){
		left = N / (a * 10);
		now = N / a % 10;
		right = N % a;
		if(now == 0) ans += left * a;
		else if(now == 1) ans += left * a + right + 1;
		else ans += (left+1) * a;
		a *= 10;
	}
	printf("%d\n", ans);
	return 0;
}