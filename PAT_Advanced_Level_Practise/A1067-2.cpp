#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int pos[MAXN];

int main(){
	int N;
	scanf("%d", &N);
	int left = N - 1;
	for(int i = 0; i < N; ++i){
		int num;
		scanf("%d", &num);
		pos[num] = i;
		if(num == i && num != 0){
			--left;
		}
	}
	int k = 1;
	int ans = 0;
	while(left > 0){
		if(pos[0] == 0){
			while(k < N){
				if(pos[k] != k){
					swap(pos[0], pos[k]);
					++ans;
					break;
				}
				++k;
			}
		}
		while(pos[0] != 0){
			swap(pos[0], pos[pos[0]]);
			++ans;
			--left;
		}
	}
	printf("%d", ans);
	return 0;
}