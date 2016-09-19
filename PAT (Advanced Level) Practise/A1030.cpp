#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 510;
const int INF = 0x3fffffff;
int N, M, S, D;
struct Node{
	int city, dis, cost;
	Node(int c, int d, int co):city(c), dis(d), cost(co){}
};
vector<Node> Adj[MAXN];
int d[MAXN], c[MAXN], pre[MAXN];
bool vis[MAXN] = {false};

void Dijkstra(int s){
	fill(d, d+N, INF);
	d[s] = 0;
	fill(c, c+N, INF);
	c[s] = 0;
	for(int i = 0; i < N; ++i) pre[i] = i;
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
		for(int j = 0; j < Adj[u].size(); ++j){
			int v = Adj[u][j].city;
			int dis = Adj[u][j].dis;
			int cost = Adj[u][j].cost;
			if(vis[v] == false && d[v] > d[u] + dis){
				d[v] = d[u] + dis;
				c[v] = c[u] + cost;
				pre[v] = u;
			}else if(vis[v] == false && d[v] == d[u] + dis && c[v] > c[u] + cost){
				c[v] = c[u] + cost;
				pre[v] = u;
			}
		}
	}
}

void DFS(int s, int v){
	if(v == s){
		printf("%d ", v);
		return;
	}
	DFS(s, pre[v]);
	printf("%d ", v);
}

int main(){
	scanf("%d%d%d%d", &N, &M, &S, &D);
	for(int i = 0; i < M; ++i){
		int c1, c2, dis, cost;
		scanf("%d%d%d%d", &c1, &c2, &dis, &cost);
		Adj[c1].push_back(Node(c2, dis, cost));
		Adj[c2].push_back(Node(c1, dis, cost));
	}
	Dijkstra(S);
	DFS(S, D);
	printf("%d %d", d[D], c[D]);
	return 0;
}