#include <cstdio>

int main(){
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);
	a += b;
	int c[40], num = 0;
	do{
		c[num++] = a % d;
		a /= d;
	}while(a != 0);
	for(int i = num - 1; i >= 0; --i){
		printf("%d", c[i]);
	}
	//printf("\n");
	return 0;
}