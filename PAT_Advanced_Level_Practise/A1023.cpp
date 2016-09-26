#include <cstdio>
#include <cstring>
using namespace std;

struct BigInt{
	int digit[25], len;
	BigInt() : len(0) {
		memset(digit, 0, sizeof(digit));
	}
} a, c;

BigInt transfer(char str[]){
	BigInt c;
	c.len = strlen(str);
	for(int i = 0; i < c.len; ++i){
		c.digit[i] = str[c.len - i - 1] - '0';
	}
	return c;
}

BigInt multi(const BigInt &a, int b){
	BigInt c;
	int carry = 0;
	for(int i = 0; i < a.len; ++i){
		int temp = a.digit[i] * b + carry;
		c.digit[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0){
		c.digit[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

void print(const BigInt &a){
	for(int i = a.len - 1; i >= 0; --i){
		printf("%d", a.digit[i]);
	}
}

bool check(const BigInt &a, const BigInt &b){
	int num1[11] = {0}, num2[11] = {0};
	if(a.len != b.len) return false;
	else{
		for(int i = 0; i < a.len; ++i){
			++num1[a.digit[i]];
			++num2[b.digit[i]];
		}
		for(int i = 0; i < 11; ++i){
			if(num1[i] != num2[i]) return false;
		}
		return true;
	}
}

int main(){
	char str[25];
	scanf("%s", str);
	a = transfer(str);
	c = multi(a, 2);
	if(check(a, c)){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	print(c);
}