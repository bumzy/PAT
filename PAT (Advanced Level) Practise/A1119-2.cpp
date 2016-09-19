#include <cstdio>
using namespace std;

const int MAXN = 35;
int pre[MAXN], in[MAXN], post[MAXN], unique = 1, N;
struct Node{
	int data;
	Node *lchild, *rchild;
	Node(int _d): data(_d), lchild(NULL), rchild(NULL) {}
};

Node *creat(int preL, int preR, int postL, int postR){
	if(preL > preR) return NULL;
	else if(preL == preR){
		Node *root = new Node(pre[preL]);
		return root;
	}
	Node *root = new Node(pre[preL]);
	int k;
	for(k = preL+1; k <= preR; ++k){
		if(pre[k] == post[postR-1]){
			break;
		}
	}
	int numLeft = k - preL - 1;
	if(numLeft > 0){
		root->lchild = creat(preL+1, k-1, postL, postL+numLeft-1);
		root->rchild = creat(k, preR, postL+numLeft, postR-1);
	}else{
		unique = 0;
		root->lchild = NULL;
		root->rchild = creat(k, preR, postL+numLeft, postR-1);
	}
	return root;
}

int cnt = 0;
void inOrder(Node *root){
	if(root == NULL) return;
	inOrder(root->lchild);
	printf("%d", root->data);
	if(cnt < N-1){
		++cnt;
		printf(" ");
	}
	inOrder(root->rchild);
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < N; ++i){
		scanf("%d", &post[i]);
	}
	Node *root = creat(0, N-1, 0, N-1);
	printf("%s\n", unique ? "Yes" : "No");
	inOrder(root);
	printf("\n");
	return 0;
}