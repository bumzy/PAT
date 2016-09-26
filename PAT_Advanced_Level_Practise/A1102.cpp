#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N, inDegree[10] = {0};
struct Node{
	int lchild, rchild;
	Node(): lchild(-1), rchild(-1) {}
} node[10];

void invertTree(int root){
	if(root == -1) return;
	invertTree(node[root].lchild);
	invertTree(node[root].rchild);
	swap(node[root].lchild, node[root].rchild);
}

int cnt;
void levelOrder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int f = q.front();
		q.pop();
		printf("%d", f);
		++cnt;
		if(cnt < N) printf(" ");
		if(node[f].lchild != -1) q.push(node[f].lchild);
		if(node[f].rchild != -1) q.push(node[f].rchild);
	}
	printf("\n");
}

void inOrder(int root){
	if(root == -1) return;
	inOrder(node[root].lchild);
	printf("%d", root);
	++cnt;
	if(cnt < N) printf(" ");
	inOrder(node[root].rchild);
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		char l[2], r[2];
		scanf("%s %s", l, r);
		if(l[0] != '-'){
			int lchild = l[0] - '0';
			node[i].lchild = lchild;
			++inDegree[lchild];
		}
		if(r[0] != '-'){
			int rchild = r[0] - '0';
			node[i].rchild = rchild;
			++inDegree[rchild];
		}
	}
	int root;
	for(int i = 0; i < N; ++i){
		if(inDegree[i] == 0){
			root = i;
			break;
		}
	}
	invertTree(root);
	cnt = 0;
	levelOrder(root);
	cnt = 0;
	inOrder(root);
	return 0;
}