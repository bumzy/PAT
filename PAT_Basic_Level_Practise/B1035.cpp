#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 110;
int origin[MAXN], tempOri[MAXN], middle[MAXN], N;

bool isSame(int a[], int b[]){
	for(int i = 1; i <= N; ++i){
		if(a[i] != b[i])
			return false;
	}
	return true;
}

void init(){
	for(int i = 1; i <= N; ++i){
		tempOri[i] = origin[i];
	}
}

bool insertSort(){
	init();
	bool flag = false;
	for(int i = 2; i <= N; ++i){
		if(i != 2 && isSame(tempOri, middle)){
			flag = true;
		}
		int j = i, temp = tempOri[i];
		while(j > 1 && tempOri[j-1] > temp){
			tempOri[j] = tempOri[j-1];
			--j;
		}
		tempOri[j] = temp;
		if(flag == true){
			return true;
		}
	}
	return false;
}

bool mergeSort(){
	init();
	bool flag = false;
	for(int step = 2; step / 2 <= N; step *= 2){
		if(step != 2 && isSame(tempOri, middle)){
			flag = true;
		}
		for(int i = 1; i <= N; i += step){
			sort(tempOri+i, tempOri+min(i+step, N+1));
		}
		if(flag == true){
			return true;
		}
	}
	return false;
}

void showArray(int a[]){
	for(int i = 1; i <= N; ++i){
		if(i != 1) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
}

int main(){
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		scanf("%d", &origin[i]);
	}
	for(int i = 1; i <= N; ++i){
		scanf("%d", &middle[i]);
	}
	if(insertSort()){
		printf("Insertion Sort\n");
		showArray(tempOri);
	}else if(mergeSort()){
		printf("Merge Sort\n");
		showArray(tempOri);
	}
	return 0;
}