#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 510;
const int INF = 0x3fffffff;
int N, M, C1, C2;
int d[MAXN], num[MAXN] = {0}, w[MAXN] = {0}, weight[MAXN];
bool vis[MAXN] = {false};
struct Node{
	int id, dis;
	Node(int i=0, int d=0):id(i),dis(d){}
};
vector<Node> Adj[MAXN];

void Dijkstra(int s){
	fill(d, d+N, INF);
	d[s] = 0;
	num[s] = 1;
	w[s] = weight[s];
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
			int v = Adj[u][j].id;
			int dis = Adj[u][j].dis;
			if(vis[v] == false && d[v] > d[u] + dis){
				d[v] = d[u] + dis;
				num[v] = num[u];
				w[v] = w[u] + weight[v];
			}else if(vis[v] == false && d[v] == d[u] + dis){
				if(w[v] < w[u] + weight[v]){
					w[v] = w[u] + weight[v];
				}
				num[v] += num[u];
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	for(int i = 0; i < N; ++i){
		scanf("%d", &weight[i]);
	}
	for(int i = 0; i < M; ++i){
		int c1, c2, L;
		scanf("%d%d%d", &c1, &c2, &L);
		Adj[c1].push_back(Node(c2, L));
		Adj[c2].push_back(Node(c1, L));
	}
	Dijkstra(C1);
	printf("%d %d", num[C2], w[C2]);
	return 0;
}