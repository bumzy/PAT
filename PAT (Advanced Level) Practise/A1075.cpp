#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct User{
	//bool valid;
	int id, score[5], solved, total;
	User() : id(0), solved(0), total(0) {
		score[0] = score[1] = score[2] = score[3] = score[4] = -2;
		//memset(score, 0xff, sizeof(score));
	}
} user[10010];

struct Submit{
	int id, num, score;
} submit[100010];

bool cmpUser(const User &u1, const User &u2){
	if(u1.total != u2.total) return u1.total > u2.total;
	else if(u1.solved != u2.solved) return u1.solved > u2.solved;
	else return u1.id < u2.id;
}

bool cmpSubmit(const Submit &s1, const Submit &s2){
	if(s1.id != s2.id) return s1.id < s2.id;
	else if(s1.num != s2.num) return s1.num < s1.num;
	else return s1.score > s2.score;
}

int full_mark[5];
int N, K, M;

int main(){
	scanf("%d%d%d", &N, &K, &M);
	for(int i = 0; i < K; ++i){
		scanf("%d", &full_mark[i]);
	}
	for(int i = 0; i < M; ++i){
		scanf("%d%d%d", &submit[i].id, &submit[i].num, &submit[i].score);
	}
	sort(submit, submit + M, cmpSubmit);
	int cnt = 0;
	int curr_i = 0, next_i;
	while(curr_i < M){
		next_i = curr_i;
		while(next_i < M && submit[next_i].id == submit[curr_i].id){
			++next_i;
		}
		user[cnt].id = submit[curr_i].id;
		bool valid = false;
		while(curr_i < next_i){
			if(submit[curr_i].score > -1){
				valid = true;
			}
			if(submit[curr_i].score > user[cnt].score[submit[curr_i].num - 1]){
				if(submit[curr_i].score == -1)
					user[cnt].score[submit[curr_i].num - 1] = 0;
				else
					user[cnt].score[submit[curr_i].num - 1] = submit[curr_i].score;
			}
			++curr_i;
		}
		for(int j = 0; j < K; ++j){
			if(user[cnt].score[j] > 0){
				user[cnt].total += user[cnt].score[j];
				if(user[cnt].score[j] == full_mark[j]){
					++user[cnt].solved;
				}
			}
		}
		if(valid) ++cnt;
	}
	sort(user, user + cnt, cmpUser);
	int r = 1;
	for(int i = 0; i < cnt; ++i){
		if(i > 0 && user[i].total != user[i-1].total){
			r = i+1;
		}
		printf("%d %05d %d", r, user[i].id, user[i].total);
		for(int j = 0; j < K; ++j){
			if(user[i].score[j] >= 0)
				printf(" %d", user[i].score[j]);
			else
				printf(" -");
		}
		printf("\n");
	}
	return 0;
}