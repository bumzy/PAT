#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int N;
int num[MAXN];

bool judge(){
	for(int i = 0; i < N; ++i){
		if(num[i] != i) return false;
	}
	return true;
}

int find(int idx){
	for(int i = 0; i < N; ++i){
		if(num[i] == idx) return i;
	}
	//return -1;
}

int find_uneq(){
	for(int i = 1; i < N; ++i){
		if(num[i] != i) return i;
	}
	//return -1;
}

void print(){
	for(int i = 0; i < N; ++i){
		printf("%d ", num[i]);
	}
	printf("\n");
}

int main(){
	int idx;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &num[i]);
		if(num[i] == 0){
			idx = i;
		}
	}
	int ans = 0;
	while(!judge()){
		if(idx != 0){
			int k = find(idx);
			//printf("%d %d\n", idx, k);
			swap(num[idx], num[k]);
			idx = k;
		}else{
			int k = find_uneq();
			//printf("%d %d\n", idx, k);
			swap(num[idx], num[k]);
			idx = k;
		}
		//print();
		++ans;
	}
	printf("%d", ans);
	return 0;
}