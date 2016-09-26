#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;
int number[MAXN], CBT[MAXN], index = 0, N;

void inOrder(int root){
	if(root > N) return;
	inOrder(root * 2);
	CBT[root] = number[index++];
	inOrder(root * 2 + 1);
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &number[i]);
	}
	sort(number, number+N);
	inOrder(1);
	for(int i = 1; i <= N; ++i){
		if(i != 1) printf(" ");
		printf("%d", CBT[i]);
	}
	return 0;
}