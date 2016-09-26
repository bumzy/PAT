#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 110;
int N, M;
int cnt[MAXN] = {0};
struct Node{
	int level;
	vector<int> child;
} node[MAXN];

void levelOrder(int root){
	queue<int> q;
	q.push(root);
	node[root].level = 1;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		++cnt[node[front].level];
		for(int i = 0; i < node[front].child.size(); ++i){
			int child = node[front].child[i];
			q.push(child);
			node[child].level = node[front].level + 1;
		}
	}
}

void DFS(int index, int level){
	++cnt[level];
	for(int i = 0; i < node[index].child.size(); ++i){
		DFS(node[index].child[i], level+1);
	}
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i){
		int id, k, child;
		scanf("%d%d", &id, &k);
		for(int j = 0; j < k; ++j){
			scanf("%d", &child);
			node[id].child.push_back(child);
		}
	}
	//levelOrder(1);
	DFS(1, 1);
	int maxL = -1;
	int level = -1;
	for(int i = 1; i <= N; ++i){
		if(cnt[i] > maxL){
			maxL = cnt[i];
			level = i;
		}
	}
	printf("%d %d", maxL, level);
	return 0;
}