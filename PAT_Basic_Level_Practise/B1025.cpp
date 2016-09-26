#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
struct Node{
	int address, data, next, order;
	Node(): order(MAXN) {}
} node[MAXN];

bool cmp(const Node &n1, const Node &n2){
	return n1.order < n2.order;
}

int main(){
	int head, N, K;
	scanf("%d%d%d", &head, &N, &K);
	for(int i = 0; i < N; ++i){
		int address, data, next;
		scanf("%d%d%d", &address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}
	int p = head, cnt = 0;
	while(p != -1){
		node[p].order = cnt++;
		p = node[p].next;
	}
	sort(node, node + MAXN, cmp);
	N = cnt;
	for(int i = 0; i < N / K; ++i){
		for(int j = (i+1)*K-1; j > i*K; --j){
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j-1].address);
		}
		printf("%05d %d ", node[i*K].address, node[i*K].data);
		if(i < N/K-1){
			printf("%05d\n", node[(i+2)*K-1].address);
		}else{
			if(N % K == 0){
				printf("-1\n");
			}else{
				printf("%05d\n", node[(i+1)*K].address);
				for(int j = (i+1)*K; j < N; ++j){
					printf("%05d %d ", node[j].address, node[j].data);
					if(j < N-1)
						printf("%05d\n", node[j+1].address);
					else
						printf("-1\n");
				}
			}
		}
	}
	return 0;
}