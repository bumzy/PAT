#include <cstdio>

int main(){
	int a, b;
	bool first = true;
	while(scanf("%d%d", &a, &b) != EOF){
		if(first == true && b >= 0){
			if(b > 0)
				printf("%d %d", a*b, b-1);
			else
				printf("0 0");
			first = false;
		}else if(b > 0){
			printf(" %d %d", a*b, b-1);
		}
	}
	return 0;
}