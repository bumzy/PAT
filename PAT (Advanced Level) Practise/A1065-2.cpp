#include <cstdio>

int main(){
	int n;
	int k = 0;
	scanf("%d", &n);
	while(n--){
		long long a, b, c,result;
		scanf("%lld%lld%lld", &a, &b, &c);
		result = a + b;
		int flag;
		if(a > 0 && b > 0 && result < 0) flag = true;
		else if(a < 0 && b < 0 && result >= 0) flag = false;
		else if(result > c) flag = true;
		else flag = false;
		if(flag == true)
			printf("Case #%d: true\n", ++k);
		else
			printf("Case #%d: false\n", ++k);
	}
	return 0;
}