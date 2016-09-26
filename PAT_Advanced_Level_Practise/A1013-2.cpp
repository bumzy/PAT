#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 1000 + 10;
int N, M, K;
int father[MAXN];
bool visited[MAXN];
vector<int> Adj[MAXN];

int init(){
	for(int i = 1; i <= N; ++i){
		father[i] = i;
		visited[i] = false;
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
		father[a] = x;
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
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 0; i < M; ++i){
		int c1, c2;
		scanf("%d%d", &c1, &c2);
		Adj[c1].push_back(c2);
		Adj[c2].push_back(c1);
	}
	int currentPoint;
	for(int i = 0; i < K; ++i){
		scanf("%d", &currentPoint);
		init();
		for(int j = 1; j <= N; ++j){
			for(int k = 0; k < Adj[j].size(); ++k){
				int u = j, v = Adj[j][k];
				if(u != currentPoint && v != currentPoint){
					Union(u, v);
				}
			}
		}
		int block = 0;
		for(int i = 1; i <= N; ++i){
			if(i == currentPoint) continue;
			int fa_i = findFather(i);
			if(visited[fa_i] == false){
				++block;
				visited[fa_i] = true;
			}
		}
		printf("%d\n", block-1);
	}
	return 0;
}