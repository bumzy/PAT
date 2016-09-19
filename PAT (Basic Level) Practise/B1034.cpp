#include <cstdio>
#include <algorithm>
using namespace std;

struct Fraction{
	long long up, down;
};

long long gcd(long long a, long long b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

Fraction reduction(Fraction result){
	if(result.down < 0){
		result.down = 0-result.down;
		result.up = 0-result.up;
	}
	if(result.up == 0){
		result.down = 1;
	}else{
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}

Fraction add(const Fraction &a, const Fraction &b){
	Fraction result;
	result.up = a.up * b.down + a.down * b.up;
	result.down = a.down * b.down;
	return result;
}

Fraction sub(const Fraction &a, const Fraction &b){
	Fraction result;
	result.up = a.up * b.down - a.down * b.up;
	result.down = a.down * b.down;
	return result;
}
Fraction multi(const Fraction &a, const Fraction &b){
	Fraction result;
	result.up = a.up * b.up;
	result.down = a.down * b.down;
	return result;
}
Fraction divide(const Fraction &a, const Fraction &b){
	Fraction result;
	result.up = a.up * b.down;
	result.down = a.down * b.up;
	return result;
}

void showResult(Fraction result){
	result = reduction(result);
	if(result.up < 0) printf("(");
	if(result.down == 1) printf("%lld", result.up);
	else if(result.down < abs(result.up)){
		printf("%lld %lld/%lld", result.up/result.down, abs(result.up) % result.down, result.down);
	}else{
		printf("%lld/%lld", result.up, result.down);
	}
	if(result.up < 0) printf(")");
}

int main(){
	Fraction a, b, result;
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);

	showResult(a);
	printf(" + ");
	showResult(b);
	printf(" = ");
	showResult(add(a, b));
	printf("\n");

	showResult(a);
	printf(" - ");
	showResult(b);
	printf(" = ");
	showResult(sub(a, b));
	printf("\n");

	showResult(a);
	printf(" * ");
	showResult(b);
	printf(" = ");
	showResult(multi(a, b));
	printf("\n");

	showResult(a);
	printf(" / ");
	showResult(b);
	printf(" = ");
	if(b.up != 0)
		showResult(divide(a, b));
	else
		printf("Inf");
	printf("\n");
	return 0;
}