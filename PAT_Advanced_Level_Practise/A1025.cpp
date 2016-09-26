#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct testee{
	long long id;
	//char id[15];
	int score;
	int local_rank;
	int location;
	bool operator < (const testee &t) const{
		if(score != t.score) return score > t.score;
		else return id < t.id;
		//else return strcmp(id, t.id) < 0;
	}
};

testee all[30010];

int main(){
	int N;
	scanf("%d", &N);
	int cnt = 0;
	for(int i = 1; i <= N; ++i){
		int K;
		scanf("%d", &K);
		for(int j = 0; j < K; ++j){
			scanf("%lld%d", &all[cnt].id, &all[cnt].score);
			//scanf("%s%d", all[cnt].id, &all[cnt].score);
			all[cnt].location = i;
			++cnt;
		}
		sort(&all[cnt - K], &all[cnt]);
		all[cnt - K].local_rank = 1;
		for(int j = cnt - K + 1; j < cnt; ++j){
			if(all[j].score == all[j - 1].score){
				all[j].local_rank = all[j - 1].local_rank;
			}else{
				all[j].local_rank = j + 1 - (cnt - K);
			}
		}
	}
	printf("%d\n", cnt);
	sort(&all[0], &all[cnt]);
	int r = 1;
	for(int i = 0; i < cnt; ++i){
		if(i > 0 && all[i].score != all[i - 1].score){
			r = i + 1;
		}
		printf("%013lld %d %d %d\n", all[i].id, r, all[i].location, all[i].local_rank);
		//printf("%s %d %d %d\n", all[i].id, r, all[i].location, all[i].local_rank);
	}
	return 0;
}