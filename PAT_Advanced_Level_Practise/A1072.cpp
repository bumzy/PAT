#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1010 + 10;
const int INF = 0x3fffffff;
bool vis[MAXN] = {false}, valid[15];
int N, M, K;
double Ds;
double d[MAXN], smallest[15], average[15];
struct Node{
	int v;
	double dis;
	Node(int _v, double _dis): v(_v), dis(_dis) {}
};
vector<Node> Adj[MAXN];
vector<int> pre[MAXN];
vector<int> tempPath, path;

int strToInt(char s[]){
	int num = 0;
	int len = strlen(s);
	int w = 1;
	for(int i = len-1; i >= 0; --i){
		if(s[i] == 'G')
			num += N;
		else
			num += (s[i]-'0') * w;
		w *= 10;
	}
	return num;
}

void Dijkstra(int s){
	fill(d, d+MAXN, INF);
	fill(vis, vis+MAXN, false);
	d[s] = 0;
	for(int i = 1; i <= N+M; ++i){
		int u = -1, MIN = INF;
		for(int j = 1; j <= N+M; ++j){
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
			}
		}
	}
}

int main(){
	scanf("%d%d%d%lf", &N, &M, &K, &Ds);
	for(int i = 1; i <= M; ++i){
		smallest[i] = INF;
		average[i] = INF;
		valid[i] = true;
	}
	for(int i = 0; i < K; ++i){
		char s1[8], s2[8];
		double dis;
		scanf("%s%s%lf", s1, s2, &dis);
		int p1 = strToInt(s1);
		int p2 = strToInt(s2);
		Adj[p1].push_back(Node(p2, dis));
		Adj[p2].push_back(Node(p1, dis));
		//printf("%d %d ", p1, p2);
	}
	for(int i = 1; i <= M; ++i){
		Dijkstra(i+N);
		double sum = 0.0;
		for(int j = 1; j <= N; ++j){
			if(d[j] > Ds){
				valid[i] = false;
				break;
			}
			if(d[j] < smallest[i]){
				smallest[i] = d[j];
			}
			sum += d[j];
		}
		average[i] = sum / N;
	}
	int ans = -1;
	double sml = 0, avg = INF;
	for(int i = 1; i <= M; ++i){
		if(valid[i] == true){
			if(smallest[i] > sml){
				ans = i;
				sml = smallest[i];
				avg = average[i];
			}else if(smallest[i] == sml && average[i] < avg){
				ans = i;
				avg = average[i];
			}
		}
	}
	if(ans == -1){
		printf("No Solution");
	}else{
		printf("G%d\n%.1lf %.1lf", ans, sml, avg);
	}
	return 0;
}