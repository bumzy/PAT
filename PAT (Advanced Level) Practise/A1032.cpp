#include <cstdio>
using namespace std;

const int MAXN = 100000 + 10;
struct Node{
	char data;
	int next;
	bool flag;
} node[MAXN];

int main(){
	int h1, h2, N;
	scanf("%d%d%d", &h1, &h2, &N);
	for(int i = 0; i < N; ++i){
		int curr, next;
		char data;
		scanf("%d %c %d", &curr, &data, &next);
		node[curr].data = data;
		node[curr].next = next;
	}
	int p;
	for(p = h1; p != -1; p = node[p].next){
		node[p].flag = true;
	}
	for(p = h2; p != -1; p = node[p].next){
		if(node[p].flag == true) break;
	}
	if(p != -1)
		printf("%05d", p);
	else
		printf("-1");
	return 0;
}