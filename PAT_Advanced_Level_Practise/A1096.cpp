#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	long long n;
	scanf("%lld", &n);
	long long sqr = round(sqrt(1.0 *n)), maxLen = 0, start = 0;
	for(int i = 2; i <= sqr; ++i){
		long long temp = 1, j = i;
		while(true){
			temp *= j;
			if(n % temp != 0) break;
			if(j - i + 1 > maxLen){
				start = i;
				maxLen = j - i + 1;
			}
			++j;
		}
	}
	if(maxLen == 0) printf("1\n%lld", n);
	else{
		printf("%lld\n", maxLen);
		for(int i = 0; i < maxLen; ++i){
			if(i != 0) printf("*");
			printf("%lld", start + i);
		}
	}
	return 0;
}