#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 510;
const int INF = 0x3fffffff;
int N, M, S, E;
int preD[MAXN] = {0}, preT[MAXN] = {0};
int d[MAXN], t[MAXN], amt[MAXN];
bool vis[MAXN];
struct Node{
	int v, len, time;
	Node(int _v, int _len, int _time): v(_v), len(_len), time(_time) {}
};
vector<Node> Adj[MAXN];

void DijkstraD(int root){
	fill(d, d+MAXN, INF);
	fill(t, t+MAXN, INF);
	fill(vis, vis+MAXN, false);
	d[root] = 0;
	t[root] = 0;
	for(int i = 0; i < N; ++i){
		int u = -1, MIN = INF;
		for(int j = 0; j < N; ++j){
			if(vis[j] == false && d[j] < MIN){
				MIN = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int j = 0; j < Adj[u].size(); ++j){
			int v = Adj[u][j].v;
			int dis = Adj[u][j].len;
			int time = Adj[u][j].time;
			if(vis[v] == false && d[u] + dis < d[v]){
				d[v] = d[u] + dis;
				t[v] = t[u] + time;
				preD[v] = u;
			}else if(vis[v] == false && d[u] + dis == d[v] && t[u] + time < t[v]){
				t[v] = t[u] + time;
				preD[v] = u;
			}
		}
	}
}

void DijkstraT(int root){
	//fill(d, d+MAXN, INF);
	fill(t, t+MAXN, INF);
	fill(amt, amt+MAXN, INF);
	fill(vis, vis+MAXN, false);
	//d[root] = 0;
	t[root] = 0;
	amt[root] = 1;
	for(int i = 0; i < N; ++i){
		int u = -1, MIN = INF;
		for(int j = 0; j < N; ++j){
			if(vis[j] == false && t[j] < MIN){
				MIN = t[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int j = 0; j < Adj[u].size(); ++j){
			int v = Adj[u][j].v;
			//int dis = Adj[u][j].len;
			int time = Adj[u][j].time;
			if(vis[v] == false && t[u] + time < t[v]){
				//d[v] = d[u] + dis;
				t[v] = t[u] + time;
				amt[v] = amt[u] + 1;
				preT[v] = u;
			}else if(vis[v] == false && t[u] + time == t[v] && amt[u] + 1 < amt[v]){
				//d[v] = d[u] + dis;
				amt[v] = amt[u] + 1;
				preT[v] = u;
			}
		}
	}
}

void DFS(int v, int pre[]){
	if(v == S){
		printf("%d", v);
		return;
	}
	DFS(pre[v], pre);
	printf(" -> %d", v);
}

bool isSame(int preD[], int preT[]){
	for(int i = 0; i < N; ++i){
		if(preD[i] != preT[i]){
			return false;
		}
	}
	return true;
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i){
		int v1, v2, valid, len, time;
		scanf("%d%d%d%d%d", &v1, &v2, &valid, &len, &time);
		Adj[v1].push_back(Node(v2, len, time));
		if(valid == 0)
			Adj[v2].push_back(Node(v1, len, time));
	}
	scanf("%d%d", &S, &E);
	DijkstraD(S);
	int dis = d[E];
	//DFS(E, preD);
	DijkstraT(S);
	int time = t[E];
	//DFS(E, preT);
	if(isSame(preD, preT)){
		printf("Distance = %d; Time = %d: ", dis, time);
		DFS(E, preD);
	}else{
		printf("Distance = %d: ", dis);
		DFS(E, preD);
		printf("\nTime = %d: ", time);
		DFS(E, preT);
	}
	return 0;
}