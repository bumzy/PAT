#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
struct Node{
	int address, data, next, order, flag;
	Node() : order(MAXN), flag(1) {}
	bool operator < (const Node &n) const{
		if(flag != n.flag) return flag < n.flag;
		return order < n.order;
	}
} node[MAXN];
int nCnt[MAXN] = {0};

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
	int cnt = 0;
	for(int i = head; i != -1; i = node[i].next){
		node[i].order = cnt++;
	}
	sort(node, node + MAXN);
	int validCnt = 0;
	for(int i = 0; i < cnt; ++i){
		if(nCnt[abs(node[i].data)] == 0){
			node[i].flag = 0;
			++validCnt;
			++nCnt[abs(node[i].data)];
		}
	}
	sort(node, node + cnt);
	int i;
	for(i = 0; i < validCnt; ++i){
		if(i != validCnt-1)
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
		else
			printf("%05d %d -1\n", node[i].address, node[i].data);
	}
	for(i = validCnt; i < cnt; ++i){
		if(i != cnt-1)
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
		else
			printf("%05d %d -1\n", node[i].address, node[i].data);
	}
	return 0;
}