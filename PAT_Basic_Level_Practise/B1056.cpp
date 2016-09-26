#include <cstdio>
using namespace std;

int N, sum = 0;

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int x;
		scanf("%d", &x);
		sum += x;
	}
	printf("%d", sum * 11 * (N-1));
	return 0;
}