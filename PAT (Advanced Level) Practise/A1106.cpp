#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100000 + 10;
int N, minDepth = MAXN, cnt = 0;
double P, r;
vector<int> node[MAXN];

void DFS(int index, int depth){
	if(node[index].size() == 0){
		if(depth < minDepth){
			minDepth = depth;
			cnt = 1;
		}else if(depth == minDepth){
			++cnt;
		}
	}else{
		for(int i = 0; i < node[index].size(); ++i){
			DFS(node[index][i], depth+1);
		}
	}
}

int main(){
	scanf("%d%lf%lf", &N, &P, &r);
	r /= 100;
	for(int i = 0; i < N; ++i){
		int k, child;
		scanf("%d", &k);
		for(int j = 0; j < k; ++j){
			scanf("%d", &child);
			node[i].push_back(child);
		}
	}
	DFS(0, 0);
	printf("%.4lf %d", P*pow(1+r, minDepth), cnt);
	return 0;
}