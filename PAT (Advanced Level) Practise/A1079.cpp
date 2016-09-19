#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 100000 + 10;
struct Node{
	double price, amount;
	vector<int> child;
} node[MAXN];
int N;
double P, r;

double levelOrder(int root){
	double sum = 0.0;
	queue<int> q;
	q.push(root);
	node[root].price = P;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		if(node[front].child.size() == 0){
			sum += node[front].price * node[front].amount;
		}else{
			for(int i = 0; i < node[front].child.size(); ++i){
				int child = node[front].child[i];
				q.push(child);
				node[child].price = node[front].price * (1.0 + r/100);
			}
		}
	}
	return sum;
}

int main(){
	scanf("%d %lf %lf", &N, &P, &r);
	for(int i = 0; i < N; ++i){
		int k, id;
		scanf("%d", &k);
		if(k == 0){
			double amount;
			scanf("%lf", &amount);
			node[i].amount = amount;
		}else{
			for(int j = 0; j < k; ++j){
				scanf("%d", &id);
				node[i].child.push_back(id);
			}
		}
	}
	printf("%.1lf", levelOrder(0));
	return 0;
}