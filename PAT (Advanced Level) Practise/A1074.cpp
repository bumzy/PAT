#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
struct Node{
	int address, data, next, order;
	Node() : order(MAXN) {}
	bool operator < (const Node &n) const{
		return order < n.order;
	}
} node[MAXN];

int main(){
	int first, N, K;
	scanf("%d%d%d", &first, &N, &K);
	for(int i = 0; i < N; ++i){
		int address, data, next;
		scanf("%d%d%d", &address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}
	int cnt = 0;
	for(int i = first; i != -1; i = node[i].next){
		node[i].order = cnt++;
	}
	sort(node, node + MAXN);
	for(int i = 0; i < cnt/K; ++i){
		for(int j = (i+1)*K-1; j > i*K; --j){
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j-1].address);
		}
		printf("%05d %d ", node[i*K].address, node[i*K].data);
		if(i < cnt/K - 1){
			printf("%05d\n", node[(i+2)*K-1].address);
		}else{
			if(cnt % K == 0){
				printf("-1\n");
			}else{
				printf("%05d\n", node[(i+1)*K].address);
				for(int j = (i+1)*K; j < cnt; ++j){
					printf("%05d %d ", node[j].address, node[j].data);
					if(j < cnt - 1){
						printf("%05d\n", node[j+1].address);
					}else{
						printf("-1\n");
					}
				}
			}
		}
	}
	return 0;
}