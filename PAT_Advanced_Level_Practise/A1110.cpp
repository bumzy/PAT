#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 25;
int N, num[1048576];
struct Node{
	int lchild, rchild, inDegree;
	Node(): lchild(-1), rchild(-1), inDegree(0) {}
} node[MAXN];

int strToInt(char str[]){
	int len = strlen(str);
	int ans = 0;
	for(int i = 0; i < len; ++i){
		ans = ans * 10 + str[i] - '0';
	}
	return ans;
}

void create(int root, int index){
	if(root == -1) return;
	num[index] = root;
	create(node[root].lchild, index*2);
	create(node[root].rchild, index*2+1);
}

int main(){
	fill(num, num+MAXN, -1);
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		char str1[4], str2[4];
		int lchild = -1, rchild = -1;
		scanf("%s%s", str1, str2);
		if(str1[0] != '-'){
			lchild = strToInt(str1);
		}
		if(str2[0] != '-'){
			rchild = strToInt(str2);
		}
		node[i].lchild = lchild;
		node[i].rchild = rchild;
		node[lchild].inDegree++;
		node[rchild].inDegree++;
	}
	int root = -1;
	for(int i = 0; i < N; ++i){
		if(node[i].inDegree == 0){
			root = i;
			break;
		}
	}
	create(root, 1);
	bool flag = true;
	for(int i = 1; i <= N; ++i){
		if(num[i] == -1){
			flag = false;
			break;
		}
	}
	if(flag == false){
		printf("NO %d", root);
	}else{
		printf("YES %d", num[N]);
	}
	return 0;
}