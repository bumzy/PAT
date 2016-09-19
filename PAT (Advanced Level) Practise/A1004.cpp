#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 110;
int N, M, cnt[MAXN] = {0}, maxL = -1;
vector<int> node[MAXN];
int h[MAXN];

void DFS(int index, int level){
	if(node[index].size() == 0){
		++cnt[level];
		if(level > maxL){
			maxL = level;
		}
	}else{
		for(int i = 0; i < node[index].size(); ++i){
			DFS(node[index][i], level+1);
		}
	}
}

void BFS(int root){
	queue<int> q;
	q.push(root);
	h[root] = 1;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		if(node[front].size() == 0){
			++cnt[h[front]];
			if(maxL < h[front]){
				maxL = h[front];
			}
		}else{
			for(int i = 0; i < node[front].size(); ++i){
				int child = node[front][i];
				q.push(child);
				h[child] = h[front] + 1;
			}
		}
	}
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i){
		int id, k, child;
		scanf("%d%d", &id, &k);
		for(int j = 0; j < k; ++j){
			scanf("%d", &child);
			node[id].push_back(child);
		}
	}
	//DFS(1, 1);
	BFS(1);
	for(int i = 1; i <= maxL; ++i){
		if(i != 1) printf(" ");
		printf("%d", cnt[i]);
	}
	return 0;
}