#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 510;
const int INF = 0x3fffffff;
bool vis[MAXN] = {false};
int N, M, S, D;
int d[MAXN], G[MAXN][MAXN], cost[MAXN][MAXN], minCost = INF;
vector<int> pre[MAXN], tempPath, path;

void Dijkstra(int s){
	fill(d, d+N, INF);
	d[s] = 0;
	for(int i = 0; i < N; ++i){
		int u = -1, MIN = INF;
		for(int j = 0; j < N; ++j){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int j = 0; j < N; ++j){
			if(vis[j] == false && d[j] > d[u] + G[u][j]){
				d[j] = d[u] + G[u][j];
				pre[j].clear();
				pre[j].push_back(u);
			}else if(vis[j] == false && d[j] == d[u] + G[u][j]){
				pre[j].push_back(u);
			}
		}
	}
}

void DFS(int s, int v){
	if(v == s){
		tempPath.push_back(v);
		int tempCost = 0;
		for(int i = tempPath.size() - 1; i > 0; --i){
			int id = tempPath[i], nextId = tempPath[i-1];
			tempCost += cost[id][nextId];
		}
		if(tempCost < minCost){
			minCost = tempCost;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); ++i){
		DFS(s, pre[v][i]);
	}
	tempPath.pop_back();
}

int main(){
	scanf("%d%d%d%d", &N, &M, &S, &D);
	fill(G[0], G[0]+MAXN*MAXN, INF);
	fill(cost[0], cost[0]+MAXN*MAXN, INF);
	for(int i = 0; i < M; ++i){
		int c1, c2, dis, c;
		scanf("%d%d%d%d", &c1, &c2, &dis, &c);
		G[c1][c2] = G[c2][c1] = dis;
		cost[c1][c2] = cost[c2][c1] = c;
	}
	Dijkstra(S);
	DFS(S, D);
	for(int i = path.size()-1; i >= 0; --i){
		printf("%d ", path[i]);
	}
	printf("%d %d", d[D], minCost);
	return 0;
}