#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
struct Node{
	int address, data, next, order;
	Node() : order(MAXN*2) {}
	bool operator < (const Node &n) const{
		return order < n.order;
	}
} node[MAXN];
bool isExist[MAXN] = {false};

int main(){
	int head, N;
	scanf("%d%d", &head, &N);
	for(int i = 0; i < N; ++i){
		int address, data, next;
		scanf("%d%d%d", &address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}
	int validCnt = 0, removedCnt = 0;
	for(int i = head; i != -1; i = node[i].next){
		if(isExist[abs(node[i].data)] == false){
			isExist[abs(node[i].data)] = true;
			node[i].order = validCnt++;
		}else{
			node[i].order = MAXN + removedCnt++;
		}
	}
	sort(node, node + MAXN);
	int cnt = validCnt + removedCnt;
	for(int i = 0; i < cnt; ++i){
		if(i != validCnt-1 && i != cnt-1)
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
		else
			printf("%05d %d -1\n", node[i].address, node[i].data);
	}
	return 0;
}