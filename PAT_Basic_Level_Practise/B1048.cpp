#include <cstdio>
#include <cstring>

const char R[3] = {'J', 'Q', 'K'};
int main(){
	char A[110], B[110], ans[110];
	scanf("%s%s", A, B);
	int len_a = strlen(A);
	int len_b = strlen(B);
	int pos = 1;
	int i = len_a - 1;
	int j = len_b - 1;
	while(pos <= len_a || pos <= len_b){
		int b = j < 0 ? 0 : B[j] - '0';
		int a = i < 0 ? 0 : A[i] - '0';
		int c;
		if(pos % 2 == 0){
			c = b - a;
			c = (c < 0) ? c+10 : c;
			ans[pos] = c + '0';
		}else{
			c = (a + b) % 13;
			if(c < 10){
				ans[pos] = c + '0';
			}else{
				ans[pos] = R[c-10];
			}
		}
		++pos;
		--i;
		--j;
	}
	for(int i = pos - 1; i >= 1; --i){
		printf("%c", ans[i]);
	}
	return 0;
}