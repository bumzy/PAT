#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 10;
struct Student{
	int id;
	int score[5];
	int total;
	bool flag;
	int solved;
	Student() : id(0), total(0), flag(false), solved(0) {
		score[0] = score[1] = score[2] = score[3] = score[4] = -1;
	}
} stu[MAXN];
int N, K, M;
int full[5];

bool cmp(const Student &s1, const Student &s2){
	if(s1.total != s2.total) return s1.total > s2.total;
	else if(s1.solved != s2.solved) return s1.solved > s2.solved;
	else return s1.id < s2.id;
}

int main(){
	scanf("%d%d%d", &N, &K, &M);
	for(int i = 0; i < K; ++i){
		scanf("%d", &full[i]);
	}
	for(int i = 0; i < M; ++i){
		int id, num, score;
		scanf("%d%d%d", &id, &num, &score);
		if(score != -1){
			stu[id].flag = true;
			stu[id].id = id;
		}else{
			score = 0;
		}
		if(score > stu[id].score[num - 1]){
			stu[id].score[num - 1] = score;
		}
	}
	for(int i = 1; i <= N; ++i){
		if(stu[i].flag == true){
			for(int j = 0; j < K; ++j){
				if(stu[i].score[j] != -1){
					stu[i].total += stu[i].score[j];
				}
				if(stu[i].score[j] == full[j]){
					++stu[i].solved;
				}
			}
		}
	}
	sort(stu + 1, stu + N + 1, cmp);
	int r = 1;
	for(int i = 1; i <= N; ++i){
		if(i > 1 && stu[i].total != stu[i-1].total){
			r = i;
		}
		if(stu[i].flag == true){
			printf("%d %05d %d", r, stu[i].id, stu[i].total);
			for(int j = 0; j <K; ++j){
				if(stu[i].score[j] != -1)
					printf(" %d", stu[i].score[j]);
				else
					printf(" -");
			}
			printf("\n");
		}
	}
	return 0;
}