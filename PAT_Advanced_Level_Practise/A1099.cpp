#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 110;
int N, num[MAXN], index = 0;
struct Node{
	int data, lchild, rchild;
} node[MAXN];

void inOrder(int root){
	if(root == -1) return;
	inOrder(node[root].lchild);
	node[root].data = num[index++];
	inOrder(node[root].rchild);
}

int cnt = 0;
void levelOrder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int front = q.front();
		q.pop();
		printf("%d", node[front].data);
		++cnt;
		if(cnt < N) printf(" ");
		if(node[front].lchild != -1) q.push(node[front].lchild);
		if(node[front].rchild != -1) q.push(node[front].rchild);
	}
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d%d", &node[i].lchild, &node[i].rchild);
	}
	for(int i = 0; i < N; ++i){
		scanf("%d", &num[i]);
	}
	sort(num, num+N);
	inOrder(0);
	levelOrder(0);
	return 0;
}