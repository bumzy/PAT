#include <cstdio>
#include <cstring>
using namespace std;

struct BigInt{
	int digit[1010], len;
	BigInt() : len(0) {
		memset(digit, 0, sizeof(digit));
	}
} a, b;

BigInt transfer(char str[]){
	BigInt c;
	c.len = strlen(str);
	for(int i = 0; i < c.len; ++i){
		c.digit[i] = str[c.len - i - 1] - '0';
	}
	return c;
}

BigInt add(const BigInt &a, const BigInt &b){
	BigInt c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; ++i){
		int temp = a.digit[i] + b.digit[i] + carry;
		c.digit[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0){
		c.digit[c.len++] = carry;
	}
	return c;
}

BigInt reverse(const BigInt &a){
	BigInt c;
	c.len = a.len;
	for(int i = 0; i < a.len; ++i){
		c.digit[i] = a.digit[a.len - i - 1];
	}
	return c;
}

bool judge(const BigInt &a){
	for(int i = 0; i < a.len/2; ++i){
		if(a.digit[i] != a.digit[a.len - i - 1]) return false;
	}
	return true;
}

void print(const BigInt &a){
	for(int i = a.len - 1; i >= 0; --i){
		printf("%d", a.digit[i]);
	}
}

int main(){
	char str[1010];
	int k, cnt = 0;
	scanf("%s%d", str, &k);
	a = transfer(str);
	while(!judge(a) && cnt < k){
		b = reverse(a);
		a = add(a, b);
		++cnt;
	}
	print(a);
	printf("\n%d", cnt);
}