#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100000 + 10;
int N;
double P, r, ans = 0;
struct Node{
	double data;
	vector<int> child;
} node[MAXN];

void DFS(int index, int depth){
	if(node[index].child.size() == 0){
		ans += node[index].data * pow(1.0+r, depth);
	}else{
		for(int i = 0; i < node[index].child.size(); ++i){
			DFS(node[index].child[i], depth+1);
		}
	}
}

int main(){
	scanf("%d%lf%lf", &N, &P, &r);
	r /= 100;
	for(int i = 0; i < N; ++i){
		int k, child;
		scanf("%d", &k);
		if(k == 0){
			scanf("%lf", &node[i].data);
		}else{
			for(int j = 0; j < k; ++j){
				scanf("%d", &child);
				node[i].child.push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.1lf", ans*P);
	return 0;
}