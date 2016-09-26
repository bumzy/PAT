#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int N, num[MAXN];

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &num[i]);
	}
	sort(num, num+N);
	int E;
	bool flag = false;
	for(int i = 0; i < N; ++i){
		E = N - i;
		if(num[i] > E){
			flag = true;
			break;
		}
	}
	printf("%d", flag ? E : 0);
	return 0;
}