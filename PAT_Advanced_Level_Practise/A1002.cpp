#include <cstdio>
using namespace std;

const int MAXN = 1000 + 10;
int K;
double P[MAXN] = {0};

int main()
{
	int n;
	double a;
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d%lf", &n, &a);
		P[n] += a;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d%lf", &n, &a);
		P[n] += a;
	}
	K = 0;
	for (int i = 0; i <= 1000; ++i) {
		if (P[i]) ++K;
	}
	printf("%d", K);
	for (int i = 1000; i >= 0; --i) {
		if (P[i]) printf(" %d %.1lf", i, P[i]);
	}
	return 0;
}