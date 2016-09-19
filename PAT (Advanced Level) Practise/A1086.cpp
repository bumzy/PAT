#include <cstdio>
#include <stack>
using namespace std;

const int MAXN = 40;
int pre[MAXN], in[MAXN], N, preN = 0, inN = 0;
stack<int> st;
struct Node{
	int key;
	Node *lchild, *rchild;
};

Node *buildTree(int preL, int preR, int inL, int inR){
	if(preL > preR) return NULL;
	Node *root = new Node;
	root->key = pre[preL];
	int k;
	for(k = inL; k <= inR; ++k){
		if(pre[preL] == in[k]){
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = buildTree(preL+1, preL+numLeft, inL, k-1);
	root->rchild = buildTree(preL+numLeft+1, preR, k+1, inR);
	return root;
}

int cnt = 0;
void postOrder(Node *root){
	if(root == NULL) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d", root->key);
	++cnt;
	if(cnt < N) printf(" ");
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N*2; ++i){
		char op[8];
		int x;
		scanf("%s", op);
		if(op[1] == 'u'){
			scanf("%d", &x);
			st.push(x);
			pre[preN++] = x;
		}else{
			int top = st.top();
			st.pop();
			in[inN++] = top;
		}
	}
	Node *root = buildTree(0, N-1, 0, N-1);
	postOrder(root);
	return 0;
}