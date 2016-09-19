#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1000 + 10;
int N, M, K;
bool G[MAXN][MAXN] = {false}, visited[MAXN] ={false};

void DFS(int now, int s){
	visited[now] = true;
	for(int i = 1; i <= N; ++i){
		if(i != s && visited[i] == false && G[now][i] == true){
			DFS(i, s);
		}
	}
}

int DFSTrave(int s){
	int cnt = 0;
	for(int i = 1; i <= N; ++i){
		if(i != s && visited[i] == false){
			DFS(i, s);
			++cnt;
		}
	}
	return cnt - 1;
}

int main(){
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 0; i < M; ++i){
		int c1, c2;
		scanf("%d%d", &c1, &c2);
		G[c1][c2] = G[c2][c1] = true;
	}
	for(int i = 0; i < K; ++i){
		memset(visited, false, sizeof(visited));
		int s;
		scanf("%d", &s);
		printf("%d\n", DFSTrave(s));
	}
	return 0;
}