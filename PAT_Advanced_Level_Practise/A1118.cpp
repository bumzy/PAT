#include <cstdio>
using namespace std;

const int MAXN = 10000 + 10;
int N, Q, birdNum = 0, cnt = 0, father[MAXN];
bool isRoot[MAXN] = {false};

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
	for(int i = 0; i < MAXN; ++i){
		father[i] = i;
	}
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int k;
		scanf("%d", &k);
		if(k > 0){
			int f, x;
			scanf("%d", &f);
			if(f > birdNum) birdNum = f;
			for(int j = 0; j < k-1; ++j){
				scanf("%d", &x);
				if(x > birdNum) birdNum = x;
				Union(x, f);
			}
		}
	}
	for(int i = 1; i <= birdNum; ++i){
		isRoot[findFather(i)] = true;
	}
	for(int i = 1; i <= birdNum; ++i){
		if(isRoot[i]){
			++cnt;
		}
	}
	printf("%d %d\n", cnt, birdNum);
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%s\n", findFather(a) == findFather(b) ? "Yes" : "No");
	}
	return 0;
}