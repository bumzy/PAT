#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
const int INF = 0x7fffffff;
struct Node{
	int address, key, next, flag;
	Node() : address(-1), key(INF), next(-1), flag(1) {}
	bool operator < (const Node &n) const{
		if(flag != n.flag) return flag < n.flag;
		else return key < n.key;
	}
} node[MAXN];

int main(){
	int N, head;
	scanf("%d%d", &N, &head);
	for(int i = 0; i < N; ++i){
		int address, key, next;
		scanf("%d%d%d", &address, &key, &next);
		node[address].address = address;
		node[address].key = key;
		node[address].next = next;
	}
	int cnt = 0;
	for(int p = head; p != -1; p = node[p].next){
		node[p].flag = 0;
		++cnt;
	}
	sort(node, node + MAXN);
	if(cnt > 0){
		printf("%d %05d\n", cnt, node[0].address);
		for(int i = 0; i < cnt; ++i){
			if(i != cnt-1)
				printf("%05d %d %05d\n",node[i].address, node[i].key, node[i+1].address);
			else
				printf("%05d %d -1\n",node[i].address, node[i].key);
		}
	}else{
		printf("0 -1\n");
	}
	return 0;
}