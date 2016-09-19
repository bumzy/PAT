#include <cstdio>
#include <cstdlib>

struct Fraction{
	long long up, down;
	Fraction() : up(0), down(1) {}
} temp, sum;

long long gcd(long long a, long long b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

Fraction &reduction(Fraction &result){
	if(result.down < 0){
		result.up = 0 - result.up;
		result.down = 0 - result.down;
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
	result.up = f1.up * f2.down;
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
	if(result.down == 1) printf("%lld\n", result.up);
	else if(abs(result.up) > result.down){
		printf("%lld %lld/%lld\n", result.up/result.down, abs(result.up)%result.down, result.down);
	}else{
		printf("%lld/%lld\n", result.up, result.down);
	}
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%lld/%lld", &temp.up, &temp.down);
		sum = add(sum, temp);
	}
	showResult(sum);
	return 0;
}