#include <cstdio>
//#include <algorithm>
#include <cstdlib>
//#include <cmath>
using namespace std;

struct Fraction{
	long long up, down;
};

long long gcd(long long a, long long b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

Fraction &reduction(Fraction &result){
	if(result.down < 0){
		result.down = 0 - result.down;
		result.up = 0 - result.up;
	}
	if(result.up == 0){
		result.down = 1;
	}else{
		long long d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}

Fraction add(const Fraction &f1, const Fraction &f2){
	Fraction result;
	result.up = f1.up*f2.down + f2.up*f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction minu(const Fraction &f1, const Fraction &f2){
	Fraction result;
	result.up = f1.up*f2.down - f2.up*f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction multi(const Fraction &f1, const Fraction &f2){
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction divide(const Fraction &f1, const Fraction &f2){
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}

void showResult(Fraction &result){
	result = reduction(result);
	if(result.up < 0) printf("(");
	if(result.down == 1){
		printf("%lld", result.up);
	}else if(abs(result.up) > abs(result.down)){
		printf("%lld %lld/%lld", result.up/result.down, abs(result.up)%result.down, result.down);
	}else{
		printf("%lld/%lld", result.up, result.down);
	}
	if(result.up < 0) printf(")");
}

int main(){
	Fraction f1, f2, r;
	scanf("%lld/%lld %lld/%lld", &f1.up, &f1.down, &f2.up, &f2.down);
	
	showResult(f1);
	printf(" + ");
	showResult(f2);
	printf(" = ");
	r = add(f1, f2);
	showResult(r);
	printf("\n");

	showResult(f1);
	printf(" - ");
	showResult(f2);
	printf(" = ");
	r = minu(f1, f2);
	showResult(r);
	printf("\n");

	showResult(f1);
	printf(" * ");
	showResult(f2);
	printf(" = ");
	r = multi(f1, f2);
	showResult(r);
	printf("\n");

	showResult(f1);
	printf(" / ");
	showResult(f2);
	printf(" = ");
	if(f2.up != 0){
		r = divide(f1, f2);
		showResult(r);
	}else{
		printf("Inf");
	}
	printf("\n");
	return 0;
}