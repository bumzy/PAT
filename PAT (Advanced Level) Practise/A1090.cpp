#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100000 + 10;
int N, cnt = 0;
double P, r, maxD = -1;
struct Node{
	vector<int> child;
} node[MAXN];

void DFS(int index, int depth){
	if(node[index].child.size() == 0){
		if(depth > maxD){
			maxD = depth;
			cnt = 1;
		}else if(depth == maxD){
			++cnt;
		}
	}else{
		for(int i = 0; i < node[index].child.size(); ++i){
			DFS(node[index].child[i], depth+1);
		}
	}
}

int main(){
	int root;
	scanf("%d%lf%lf", &N, &P, &r);
	r /= 100;
	for(int i = 0; i < N; ++i){
		int supplier;
		scanf("%d", &supplier);
		if(supplier != -1)
			node[supplier].child.push_back(i);
		else
			root = i;
	}
	DFS(root, 0);
	printf("%.2lf %d", P*pow(1+r, maxD), cnt);
	return 0;
}