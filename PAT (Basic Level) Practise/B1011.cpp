#include <cstdio>
using namespace std;

int main(){
	int n, k = 1;
	scanf("%d", &n);
	long long A, B, C;
	while(n--){
		scanf("%lld%lld%lld", &A, &B, &C);
		if(A + B > C)
			printf("Case #%d: true\n", k);
		else
			printf("Case #%d: false\n", k);
		++k;
	}
	return 0;
}