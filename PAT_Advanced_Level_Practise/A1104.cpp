#include <cstdio>

const int MAXN = 100000 + 10;

int main(){
	int N;
	scanf("%d", &N);
	double sum = 0, num;
	for(int i = 1; i <= N; ++i){
		scanf("%lf", &num);
		sum += num * i * (N - i + 1);
	}
	printf("%.2lf\n", sum);
	return 0;
}