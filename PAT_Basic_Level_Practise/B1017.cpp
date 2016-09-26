#include <cstdio>
#include <cstring>
using namespace std;

struct BigInt{
	int digit[1010], len;
	BigInt() : len(0) {
		memset(digit, 0, sizeof(digit));
	}
} q, a;

BigInt transfer(char str[]){
	BigInt c;
	c.len = strlen(str);
	for(int i = 0; i < c.len; ++i){
		c.digit[i] = str[c.len - i - 1] - '0';
	}
	return c;
}

BigInt divide(const BigInt &a, int b, int &r){
	BigInt c;
	c.len = a.len;
	for(int i = c.len - 1; i >= 0; --i){
		r = r * 10 + a.digit[i];
		if(r < b){
			c.digit[i] = 0;
		}else{
			c.digit[i] = r / b;
			r %= b;
		}
	}
	while(c.len - 1 >= 1 && c.digit[c.len - 1] == 0){
		--c.len;
	}
	return c;
}

int main(){
	char str[1010];
	int b, r = 0;
	scanf("%s%d", str, &b);
	a = transfer(str);
	q = divide(a, b, r);
	for(int i = q.len - 1; i >= 0; --i){
		printf("%d", q.digit[i]);
	}
	printf(" %d\n", r);
	return 0;
}