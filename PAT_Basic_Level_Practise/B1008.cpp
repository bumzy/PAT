#include <cstdio>
using namespace std;

const int MAXN = 100 + 10;

int main(){
	int n, m, arr[MAXN];
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%d", &arr[i]);
	}
	int idx = n - m % n;
	for(int i = 0; i < n; ++i){
		printf("%d", arr[(idx + i) % n]);
		if(i != n -1) printf(" ");
	}
	return 0;
}