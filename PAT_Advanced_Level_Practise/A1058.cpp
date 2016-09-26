#include <cstdio>

const long long Gelleon = 29 * 17;
const long long Sickle = 29;

int main(){
	int a1, b1, c1;
	int a2, b2, c2;
	scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	long long x = a1 * Gelleon + b1 * Sickle + c1;
	long long y = a2 * Gelleon + b2 * Sickle + c2;
	long long sum = x + y;
	printf("%lld.%lld.%lld", sum / Gelleon, sum % Gelleon / Sickle, sum % Sickle);
	return 0;
}