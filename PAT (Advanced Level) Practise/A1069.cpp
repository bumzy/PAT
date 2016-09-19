#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

void to_array(int n, int num[]){
	for(int i = 0; i < 4; ++i){
		num[i] = n % 10;
		n /= 10;
	}
}

int to_number(int num[]){
	int sum = 0;
	for(int i = 0; i < 4; ++i){
		sum = sum * 10 + num[i];
	}
	return sum;
}

int main(){
	int n, MAX, MIN, num[5];
	scanf("%d", &n);
	while(true){
		to_array(n, num);
		sort(num, num + 4);
		MIN = to_number(num);
		sort(num, num + 4, greater<int>());
		MAX = to_number(num);
		n = MAX - MIN;
		printf("%04d - %04d = %04d\n", MAX, MIN, n);
		if(n == 0 || n == 6174) break;
	}
	return 0;
}