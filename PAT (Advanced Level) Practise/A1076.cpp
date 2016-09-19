#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1000 + 10;
int N, L;
struct Node{
	int v, level;
	Node(int a, int b = 0): v(a),level(b){}
};
vector<Node> Adj[MAXN];
bool inq[MAXN] = {false};

int BFS(int s){
	int numForward = 0;
	queue<Node> q;
	q.push(Node(s, 0));
	inq[s] = true;
	while(!q.empty()){
		Node front = q.front();
		q.pop();
		int v = front.v;
		for(int i = 0; i < Adj[v].size(); ++i){
			Node next = Adj[v][i];
			next.level = front.level + 1;
			if(inq[next.v] == false && next.level <= L){
				q.push(next);
				inq[next.v] = true;
				++numForward;
			}
		}
	}
	return numForward;
}

int main(){
	scanf("%d%d", &N, &L);
	for(int i = 1; i <= N; ++i){
		int k, follower;
		scanf("%d", &k);
		for(int j = 0; j < k; ++j){
			scanf("%d", &follower);
			Adj[follower].push_back(Node(i));
		}
	}
	int K, s;
	scanf("%d", &K);
	for(int i = 0; i < K; ++i){
		memset(inq, false, sizeof(inq));
		scanf("%d", &s);
		printf("%d\n", BFS(s));
	}
	return 0;
}