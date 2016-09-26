#include <cstdio>
#include <algorithm>
using namespace std;

//map<int, int> coin;
int coin[1010] = {0};
int num[100010];

int main(){
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i){
		int v;
		scanf("%d", &v);
		num[i] = v;
		++coin[v];
	}
	sort(num, num + N);
	bool flag = false;
	for(int i = 0; i < N; ++i){
		if(i > 0 && num[i] == num[i-1]) continue;
		if((num[i]*2 != M && coin[M-num[i]] > 0) || (num[i]*2 == M && coin[num[i]] >= 2)){
			printf("%d %d", num[i], M-num[i]);
			flag = true;
			break;
		}
	}
	if(flag == false)
		printf("No Solution");
	return 0;
}