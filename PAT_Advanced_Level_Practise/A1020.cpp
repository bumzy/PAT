#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 40;
int post[MAXN], in[MAXN];
struct Node{
	int key;
	Node *lchild, *rchild;
};

Node *newNode(int key){
	Node *node = new Node;
	node->key = key;
	node->lchild = node->rchild = NULL;
	return node;
}

Node *buildTree(int postL, int postR, int inL, int inR){
	if(postL > postR) return NULL;
	Node *root = newNode(post[postR]);
	int k;
	for(k = inL; k <= inR; ++k){
		if(post[postR] == in[k]) break;
	}
	int numLeft = k - inL;
	root->lchild = buildTree(postL, postL+numLeft-1, inL, k-1);
	root->rchild = buildTree(postL+numLeft, postR-1, k+1, inR);
	return root;
}

void levelOrder(Node *root){
	int first = true;
	queue<Node *> q;
	q.push(root);
	while(!q.empty()){
		Node *node = q.front();
		q.pop();
		if(first == false){
			printf(" ");
		}else{
			first = false;
		}
		printf("%d", node->key);
		if(node->lchild != NULL) q.push(node->lchild);
		if(node->rchild != NULL) q.push(node->rchild);
	}
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &post[i]);
	}
	for(int i = 0; i < N; ++i){
		scanf("%d", &in[i]);
	}
	Node *root = buildTree(0, N-1, 0, N-1);
	levelOrder(root);
	return 0;
}