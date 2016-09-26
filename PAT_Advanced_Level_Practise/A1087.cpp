#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 200 + 10;
const int INF = 0x3fffffff;
bool vis[MAXN];
int N, K, maxHpy = -1, maxAvgHpy = -1;
int d[MAXN], weight[MAXN], num[MAXN];
struct Node {
	int v, dis;
	Node(int _v, int _dis): v(_v), dis(_dis){}
};
vector<Node> Adj[MAXN];
vector<int> pre[MAXN];
vector<int> tempPath, path;
map<string, int> strToIntMap;
map<int, string> intToStrMap;

int index = 0;
int strToInt(const char name[]){
	string str(name);
	if(strToIntMap.find(str) != strToIntMap.end()){
		return strToIntMap[str];
	}else{
		strToIntMap[str] = index;
		intToStrMap[index] = str;
		return index++;
	}
}

void Dijkstra(int s){
	fill(d, d+N, INF);
	fill(vis, vis+N, false);
	fill(num, num+N, 0);
	d[s] = 0;
	num[s] = 1;
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
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if(vis[v] == false && d[v] > d[u] + dis){
				d[v] = d[u] + dis;
				num[v] = num[u];
				pre[v].clear();
				pre[v].push_back(u);
			}else if(vis[v] == false && d[v] == d[u] + dis){
				num[v] += num[u];
				pre[v].push_back(u);
			}
		}
	}
}

void DFS(int s, int v){
	if(s == v){
		tempPath.push_back(v);
		int hpy = 0, avgHpy = 0;
		for(int i = tempPath.size()-1; i >= 0; --i){
			int u = tempPath[i];
			hpy += weight[u];
		}
		avgHpy = hpy / (tempPath.size()-1);
		if(hpy > maxHpy){
			maxHpy = hpy;
			maxAvgHpy = avgHpy;
			path = tempPath;
		}else if(hpy == maxHpy && avgHpy > maxHpy){
			maxAvgHpy = avgHpy;
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
	char name[4];
	int id;
	scanf("%d%d%s", &N, &K, name);
	id = strToInt(name);
	weight[id] = 0;
	for(int i = 0; i < N-1; ++i){
		scanf("%s", name);
		id = strToInt(name);
		scanf("%d", &weight[id]);
	}
	for(int i = 0; i < K; ++i){
		char name1[4], name2[4];
		int cost;
		scanf("%s%s%d", name1, name2, &cost);
		int id1 = strToInt(name1);
		int id2 = strToInt(name2);
		Adj[id1].push_back(Node(id2, cost));
		Adj[id2].push_back(Node(id1, cost));
	}
	Dijkstra(0);
	int e = strToInt("ROM");
	DFS(0, e);
	printf("%d %d %d %d\n", num[e], d[e], maxHpy, maxAvgHpy);
	for(int i = path.size()-1; i >=0; --i){
		printf("%s", intToStrMap[path[i]].c_str());
		if(i != 0) printf("->");
	}
	return 0;
}