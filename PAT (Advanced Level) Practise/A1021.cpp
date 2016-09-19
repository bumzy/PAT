#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 10000 + 10;
int N, depth[MAXN];
bool visited[MAXN];
vector<int> Adj[MAXN];

void init(){
	for(int i = 1; i <= N; ++i){
		//depth[i] = 0;
		visited[i] = false;
	}
}

void DFS(int s, int d, int &maxD){
	visited[s] = true;
	if(d > maxD) maxD = d;
	for(int i = 0; i < Adj[s].size(); ++i){
		int u = Adj[s][i];
		if(visited[u] == false){
			DFS(u, d+1, maxD);
		}
	}
}

int getNumComponets(){
	int t, cnt = 0;
	for(int i = 1; i <= N; ++i){
		if(visited[i] == false){
			DFS(i, 0, t);
			++cnt;
		}
	}
	return cnt;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N-1; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	init();
	int components = getNumComponets();
	if(components != 1){
		printf("Error: %d components\n", components);
	}else{
		int maxD = 0;
		for(int i = 1; i <= N; ++i){
			init();
			DFS(i, 0, depth[i]);
			if(depth[i] > maxD){
				maxD = depth[i];
			}
		}
		for(int i = 1; i <= N; ++i){
			if(depth[i] == maxD){
				printf("%d\n", i);
			}
		}
	}
	return 0;
}