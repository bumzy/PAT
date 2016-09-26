#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 510;
const int INF = 0x3fffffff;
bool vis[MAXN] = {false};
int Cmax, N, Sp, M;
int d[MAXN], weight[MAXN], minNeed = INF, minRemain = INF;
struct Node{
	int v, dis;
	Node(int _v, int _dis): v(_v), dis(_dis) {}
};
vector<Node> Adj[MAXN];
vector<int> pre[MAXN];
vector<int> tempPath, path;

void Dijkstra(int s){
	fill(d, d+N+1, INF);
	d[s] = 0;
	for(int i = 0; i <= N; ++i){
		int u = -1, MIN = INF;
		for(int j = 0; j <= N; ++j){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int j = 0; j < Adj[u].size(); ++j){
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if(vis[v] == false && d[v] > d[u] + dis){
				d[v] = d[u] + dis;
				pre[v].clear();
				pre[v].push_back(u);
			}else if(vis[v] == false && d[v] == d[u] + dis){
				pre[v].push_back(u);
			}
		}
	}
}

void DFS(int s, int v){
	if(v == s){
		tempPath.push_back(v);
		int need = 0, remain = 0;
		for(int i = tempPath.size()-1; i >= 0; --i){
			int id = tempPath[i];
			if(weight[id] > 0){
				remain += weight[id];
			}else{
				if(remain > abs(weight[id])){
					remain -= abs(weight[id]);
				}else{
					need += abs(weight[id]) - remain;
					remain = 0;
				}
			}
		}
		if(need < minNeed){
			minNeed = need;
			minRemain = remain;
			path = tempPath;
		}else if(need == minNeed && remain < minRemain){
			minRemain = remain;
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
	scanf("%d%d%d%d", &Cmax, &N, &Sp, &M);
	weight[0] = 0;
	for(int i = 1; i <= N; ++i){
		scanf("%d", &weight[i]);
		weight[i] -= Cmax/2;
	}
	for(int i = 0; i < M; ++i){
		int s1, s2, t;
		scanf("%d%d%d", &s1, &s2, &t);
		Adj[s1].push_back(Node(s2, t));
		Adj[s2].push_back(Node(s1, t));
	}
	Dijkstra(0);
	DFS(0, Sp);
	printf("%d ", minNeed);
	for(int i = path.size()-1; i >= 0; --i){
		printf("%d", path[i]);
		if(i != 0) printf("->");
	}
	printf(" %d", minRemain);
	return 0;
}