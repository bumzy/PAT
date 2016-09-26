#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int x, y;
	scanf("%d%d", &x, &y);
	double n = (y -x)/100.0;
	int m = floor(n + 0.5);
	int ss = m%60;
	int mm = (m/60)%60;
	int hh = (m/3600);
	printf("%02d:%02d:%02d", hh, mm, ss);
	return 0;
}