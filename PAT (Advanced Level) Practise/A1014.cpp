#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Window{
	int popTime, endTime;
	queue<int> q;
} window[20];
int ans[1010], needTime[1010];
int N, M, K, Q;

int convertTime(int h, int m){
	return h * 60 + m;
}

int main(){
	int index = 0;
	int startTime = convertTime(8, 0);
	int endTime = convertTime(17, 0);
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	for(int i = 0; i < K; ++i){
		scanf("%d", &needTime[i]);
	}
	for(int i = 0; i < N; ++i){
		window[i].popTime = window[i].endTime = startTime;
	}
	for(int i = 0; i < min(N*M, K); ++i){
		window[index % N].q.push(index);
		window[index % N].endTime += needTime[index];
		if(index < N) window[index % N].popTime += needTime[index];
		ans[index] = window[index % N].endTime;
		++index;
	}
	for( ; index < K; ++index){
		int idx = -1, minPopTime = 0x7fffffff;
		for(int j = 0; j < N; ++j){
			if(window[j].popTime < minPopTime){
				idx = j;
				minPopTime = window[j].popTime;
			}
		}
		Window &W = window[idx];
		W.q.pop();
		W.q.push(index);
		W.endTime += needTime[index];
		W.popTime += needTime[W.q.front()];
		ans[index] = W.endTime;
	}
	for(int i = 0; i < Q; ++i){
		int query;
		scanf("%d", &query);
		if(ans[query-1] - needTime[query-1] >= endTime){
			printf("Sorry\n");
		}else{
			printf("%02d:%02d\n", ans[query-1]/60, ans[query-1]%60);
		}
	}
	return 0;
}