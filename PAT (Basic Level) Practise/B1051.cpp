#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	//printf("%.2lf", -0.025);
	double R1, R2, P1, P2, R, P, A, B;
	scanf("%lf%lf%lf%lf", &R1, &P1, &R2, &P2);
	R = R1 * R2;
	P = P1 + P2;
	A = R * cos(P);
	B = R * sin(P);
	if(fabs(A) < 0.005) A = 0;
	if(fabs(B) < 0.005) B = 0;
	if(B >= 0){
		printf("%.2lf+%.2lfi", A, B);
	}else{
		printf("%.2lf%.2lfi", A, B);
	}
	return 0;
}