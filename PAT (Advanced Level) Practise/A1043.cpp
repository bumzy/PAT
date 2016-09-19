#include <cstdio>
#include <vector>
using namespace std;

int N;
struct Node{
	int data;
	Node *lchild, *rchild;
};
vector<int> origin, pre, preM, post, postM;

void insert(Node *&root, int data){
	if(root == NULL){
		root = new Node;
		root->data = data;
		root->lchild = root->rchild = NULL;
		return;
	}
	if(data < root->data) insert(root->lchild, data);
	else insert(root->rchild, data);
}

void preOrder(Node *root, vector<int> &vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->lchild, vi);
	preOrder(root->rchild, vi);
}

void preOrderMirror(Node *root, vector<int> &vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->rchild, vi);
	preOrderMirror(root->lchild, vi);
}

void postOrder(Node *root, vector<int> &vi){
	if(root == NULL) return;
	postOrder(root->lchild, vi);
	postOrder(root->rchild, vi);
	vi.push_back(root->data);
}

void postOrderMirror(Node *root, vector<int> &vi){
	if(root == NULL) return;
	postOrderMirror(root->rchild, vi);
	postOrderMirror(root->lchild, vi);
	vi.push_back(root->data);
}

int main(){
	scanf("%d", &N);
	Node *root = NULL;
	for(int i = 0; i < N; ++i){
		int data;
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	}
	preOrder(root, pre);
	preOrderMirror(root, preM);
	postOrder(root, post);
	postOrderMirror(root, postM);
	if(origin == pre){
		printf("YES\n");
		for(int i = 0; i < post.size(); ++i){
			if(i != 0) printf(" ");
			printf("%d", post[i]);
		}
	}else if(origin == preM){
		printf("YES\n");
		for(int i = 0; i < postM.size(); ++i){
			if(i != 0) printf(" ");
			printf("%d", postM[i]);
		}
	}else{
		printf("NO");
	}
	return 0;
}