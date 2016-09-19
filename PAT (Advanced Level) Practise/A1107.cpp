#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 1010;
int N, father[MAXN], hobby[MAXN] = {0}, cluster[MAXN] = {0};

void init(){
	for(int i = 1; i <= N; ++i){
		father[i] = i;
	}
}

int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

int main(){
	scanf("%d", &N);
	init();
	for(int i = 1; i <= N; ++i){
		int k, h;
		scanf("%d:", &k);
		for(int j = 0; j < k; ++j){
			scanf("%d", &h);
			if(hobby[h] == 0){
				hobby[h] = i;
			}else{
				Union(hobby[h], i);
			}
		}
	}
	for(int i = 1; i <= N; ++i){
		++cluster[findFather(i)];
		//printf("%d ", findFather(i));
	}
	sort(cluster+1, cluster+N+1, greater<int>());
	int cnt = 0;
	for(int i = 1; i <= N; ++i){
		if(cluster[i] != 0)
			++cnt;
	}
	printf("%d\n", cnt);
	for(int i = 1; i <= cnt; ++i){
		if(i != 1) printf(" ");
		printf("%d", cluster[i]);
	}
	return 0;
}