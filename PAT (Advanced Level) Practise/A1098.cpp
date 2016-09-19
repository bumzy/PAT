#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 110;
int N;
int origin[MAXN], middle[MAXN], insert[MAXN], heap[MAXN];

void init(){
	for(int i = 1; i <= N; ++i){
		insert[i] = origin[i];
		heap[i] = origin[i];
	}
}

void print(int a[]){
	for(int i = 1; i <= N; ++i){
		if(i != 1) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
}

bool judge(int a[], int b[]){
	for(int i = 1; i <= N; ++i){
		if(a[i] != b[i]) return false;
	}
	return true;
}

bool insertSort(){
	bool flag = false;
	for(int i = 2; i <= N && flag == false; ++i){
		if(i != 2 && judge(insert, middle)) flag = true;
		int temp = insert[i];
		int j = i;
		while(j >= 2 && temp < insert[j-1]){
			insert[j] = insert[j-1];
			--j;
		}
		insert[j] = temp;
		//print(insert);
	}
	return flag;
}

void downAjust(int low, int high){
	int i = low, j = i * 2;
	while(j <= high){
		if(j + 1 <= high && heap[j+1] > heap[j]){
			j = j + 1;
		}
		if(heap[j] > heap[i]){
			swap(heap[j], heap[i]);
			i = j;
			j = i * 2;
		}else{
			break;
		}
	}
}

void creatHeap(){
	for(int i = N/2; i >= 1; --i){
		downAjust(i, N);
	}
}

bool heapSort(){
	bool flag = false;
	creatHeap();
	for(int i = N; i > 1 && flag == false; --i){
		if(i != N && judge(heap, middle)) flag = true;
		swap(heap[i], heap[1]);
		downAjust(1, i-1);
		//print(heap);
	}
	return flag;
}

int main(){
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		scanf("%d", &origin[i]);
	}
	for(int i = 1; i <= N; ++i){
		scanf("%d", &middle[i]);
	}
	init();
	if(insertSort()){
		printf("Insertion Sort\n");
		print(insert);
	}else if(heapSort()){
		printf("Heap Sort\n");
		print(heap);
	}
	return 0;
}