#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
struct Mouse{
	int weight, rank;
} mouse[MAXN];

int main(){
	queue<int> q;
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i){
		scanf("%d", &mouse[i].weight);
	}
	for(int i = 0; i < N; ++i){
		int order;
		scanf("%d", &order);
		q.push(order);
	}
	int temp = N, group;
	while(q.size() != 1){
		if(temp % M == 0) group = temp / M;
		else group = temp / M + 1;
		for(int i = 0; i < group; ++i){
			int k = q.front();
			for(int j = 0; j < M; ++j){
				if(i * M + j >= temp) break;
				int front = q.front();
				if(mouse[front].weight > mouse[k].weight){
					k = front;
				}
				mouse[front].rank = group + 1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}
	mouse[q.front()].rank = 1;
	for(int i = 0; i < N; ++i){
		if(i != 0) printf(" ");
		printf("%d", mouse[i].rank);
	}
	return 0;
}