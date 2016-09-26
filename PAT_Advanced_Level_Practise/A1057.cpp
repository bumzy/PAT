#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

const int MAXN  = 100000 + 10;
const int sqrN = 316;
int N;
stack<int> st;
int block[sqrN] = {0}, table[MAXN] ={0};

void peekMidian(int K){
	int sum = 0, idx = 0;
	while(sum + block[idx] < K){
		sum += block[idx++];
	}
	int num = sqrN * idx;
	while(sum + table[num] < K){
		sum += table[num++];
	}
	printf("%d\n", num);
}

void push(int x){
	st.push(x);
	++block[x/sqrN];
	++table[x];
}

void pop(){
	int x = st.top();
	st.pop();
	--block[x/sqrN];
	--table[x];
	printf("%d\n", x);
}

int main(){
	char str[20];
	int key;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%s", str);
		if(str[1] == 'u'){
			scanf("%d", &key);
			push(key);
		}else if(str[1] == 'o'){
			if(st.empty()){
				printf("Invalid\n");
			}else{
				pop();
			}
		}else if(str[1] == 'e'){
			if(st.empty()){
				printf("Invalid\n");
			}else{
				int K = st.size();
				if(K%2 == 0) K = K / 2;
				else K = (K+1) /2;
				peekMidian(K);
			}
		}
	}
	return 0;
}