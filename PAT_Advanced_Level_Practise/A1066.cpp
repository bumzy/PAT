#include <cstdio>
#include <algorithm>
using namespace std;

int N;
struct Node{
	int data, height;
	Node *lchild, *rchild;
	Node(int d) : data(d), height(1), lchild(NULL), rchild(NULL) {}
};

int getHeight(Node *root){
	if(root == NULL) return 0;
	else return root->height;
}

void updateHeight(Node *root){
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(Node *root){
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void R(Node *&root){
	Node *temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void L(Node *&root){
	Node *temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(Node *&root, int data){
	if(root == NULL){
		root = new Node(data);
	}else if(data < root->data){
		insert(root->lchild, data);
		updateHeight(root);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1){
				R(root);
			}else if(getBalanceFactor(root->lchild) == -1){
				L(root->lchild);
				R(root);
			}
		}
	}else{
		insert(root->rchild, data);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->rchild) == -1){
				L(root);
			}else if(getBalanceFactor(root->rchild) == 1){
				R(root->rchild);
				L(root);
			}
		}
	}
}

void free(Node *root){
	if(root == NULL) return;
	free(root->lchild);
	free(root->rchild);
	delete root;
	root = NULL;
}

int main(){
	scanf("%d", &N);
	Node *root = NULL;
	for(int i = 0; i < N; ++i){
		int data;
		scanf("%d", &data);
		insert(root, data);
	}
	printf("%d", root->data);
	free(root);
	return 0;
}