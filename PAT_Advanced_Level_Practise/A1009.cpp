#include <cstdio>
#include <cstdlib>
const double E = 1e-15;
int main(){
	double a[1010] = {0.0}, b[1010] = {0.0}, c[2010] = {0.0};
	int k, n;
	double x;
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		scanf("%d %lf", &n, &x);
		a[n] = x;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		scanf("%d %lf", &n, &x);
		b[n] = x;
	}
	for(int i = 0; i < 1001; ++i){
		for(int j = 0; j < 1001; ++j){
			if(a[i] != 0 && b[j] != 0){
				n = i + j;
				x = a[i] * b[j];
				c[n] += x;
			}
		}
	}
	int count = 0;
	for(int i = 0; i <= 2000; ++i){
		if(c[i] != 0){
			++count;
		}
	}
	printf("%d", count);
	for(int i = 2000; i >= 0; --i){
		if(c[i] != 0){
			printf(" %d %.1f", i, c[i]);
		}
	}
	return 0;
}