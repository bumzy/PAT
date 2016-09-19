#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 110;
int initial[MAXN];
int partial[MAXN];
int ans[MAXN];
int N;

void init(){
	for(int i = 0; i < N; ++i){
		ans[i] = initial[i];
	}
}

void print(){
	for(int i = 0; i < N; ++i){
		if(i != 0) printf(" ");
		printf("%d", ans[i]);
	}
}

bool judge(){
	for(int i = 0; i < N; ++i){
		if(ans[i] != partial[i]) return false;
	}
	return true;
}

void insertion(int i){
	int j = i - 1;
	int tmp = ans[i];
	while(j >= 0 && ans[j] > tmp){
		ans[j+1] = ans[j];
		--j;
	}
	ans[j+1] = tmp;
}

bool insert_sort(){
	init();
	for(int i = 1; i < N; ++i){
		insertion(i);
		if(judge()){
			insertion(i+1);
			return true;
		}
	}
	return false;
}

void merge(int L1, int R1, int L2, int R2){
	int i = L1, j = L2, tmp[MAXN], index = 0;
	while(i <= R1 && j <= R2){
		if(ans[i] <= ans[j]) tmp[index++] = ans[i++];
		else tmp[index++] = ans[j++];
	}
	while(i <= R1) tmp[index++] = ans[i++];
	while(j <= R2) tmp[index++] = ans[j++];
	for(i = 0; i < index; ++i){
		ans[L1 + i] = tmp[i];
	}
}

bool merge_sort(){
	init();
	for(int step = 2; step / 2 < N; step *= 2){
		for(int i = 0; i < N; i += step){
			int mid = i + step/2 - 1;
			merge(i, mid, mid + 1, min(i + step - 1, N-1));
		}
		if(judge()){
			step *= 2;
			for(int i = 0; i < N; i += step){
				int mid = i + step/2 - 1;
				merge(i, mid, mid + 1, min(i + step - 1, N-1));
			}
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &initial[i]);
	}
	for(int i = 0; i < N; ++i){
		scanf("%d", &partial[i]);
	}
	if(insert_sort()) printf("Insertion Sort\n");
	else if(merge_sort()) printf("Merge Sort\n");
	print();
	return 0;
}