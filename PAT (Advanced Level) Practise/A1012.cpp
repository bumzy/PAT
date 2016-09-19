#include <cstdio>
#include <algorithm>
//#include <vector>
using namespace std;

const char COURSE[4] = {'A', 'C', 'M', 'E'};
int now;
struct Student{
	int id;
	int score[4];
	//int Rank[4];
}stu[2010];

int Rank[1000000][4] = {0};

bool cmp(const Student &s1, const Student &s2){
	return s1.score[now] > s2.score[now];
}

int main(){
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i){
		scanf("%d%d%d%d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
		stu[i].score[0] = stu[i].score[1] + stu[i].score[2] + stu[i].score[3];
	}
	for(now = 0; now < 4; ++now){
		sort(stu, stu + N, cmp);
		Rank[stu[0].id][now] = 1;
		for(int i = 1; i < N; ++i){
			if(stu[i].score[now] == stu[i - 1].score[now])
				Rank[stu[i].id][now] = Rank[stu[i-1].id][now];
			else
				Rank[stu[i].id][now] = i + 1;
		}
	}
	for(int i = 0; i < M; ++i){
		int id;
		scanf("%d", &id);
		if(Rank[id][0] == 0){
			printf("N/A\n");
		}else{
			int k = 0;
			for(int j = 1; j < 4; ++j){
				if(Rank[id][j] < Rank[id][k]){
					k = j;
				}
			}
			printf("%d %c\n", Rank[id][k], COURSE[k]);
		}
	}
	return 0;
}