#include <cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int s1=0, s2=0;
	while(n--){
		int a1, b1, a2, b2;
		scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
		if(b1 == a1 + a2 && b2 == a1 + a2) continue;
		else if(b1 == a1 + a2) ++s2;
		else if(b2 == a1 + a2) ++s1;
	}
	printf("%d %d", s1, s2);
	return 0;
}