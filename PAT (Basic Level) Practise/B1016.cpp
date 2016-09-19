#include <cstdio>
#include <cstring>
using namespace std;

long long calP(char *s, int D){
	long long P = 0;
	int n = strlen(s);
	for(int i = 0; i < n; ++i){
		if(s[i] - '0' == D){
			P = P*10 + D;
		}
	}
	return P;
}

int main(){
	char A[20], B[20];
	int Da, Db, Pa=0, Pb=0;
	scanf("%s%d%s%d", A, &Da, B, &Db);
	printf("%lld", calP(A, Da) + calP(B, Db));
	return 0;
}