#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1010, MAXM = 110;
int N, M;
int stu[MAXN] = {0};
struct Question{
	int id, score, num, ansNum, ans[6], wrongNum;
} ques[MAXM];

bool cmp(const Question &q1, const Question &q2){
	if(q1.wrongNum != q2.wrongNum) return q1.wrongNum > q2.wrongNum;
	else return q1.id < q2.id;
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i){
		scanf("%d%d%d", &ques[i].score, &ques[i].num, &ques[i].ansNum);
		for(int j = 0; j < ques[i].ansNum; ++j){
			char str[4];
			scanf("%s", str);
			ques[i].ans[j] = str[0] - 'a';
		}
		ques[i].id = i + 1;
		ques[i].wrongNum = 0;
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			int ansNum = 0, ans[6];
			char str[4];
			scanf("%s", str);
			ansNum = str[1] - '0';
			for(int k = 0; k < ansNum; ++k){
				scanf("%s", str);
				ans[k] = str[0] - 'a';
			}
			bool flag = true;
			if(ansNum != ques[j].ansNum){
				flag = false;
			}else{
				for(int k = 0; k < ansNum; ++k){
					if(ans[k] != ques[j].ans[k]){
						flag = false;
					}
				}
			}
			if(flag == true){
				stu[i] += ques[j].score;
			}else{
				++ques[j].wrongNum;
			}
		}
		printf("%d\n", stu[i]);
	}
	sort(ques, ques+M, cmp);
	if(ques[0].wrongNum == 0){
		printf("Too simple");
	}else{
		int max = ques[0].wrongNum;
		printf("%d", max);
		for(int i = 0; i < M; ++i){
			if(ques[i].wrongNum == max){
				printf(" %d", ques[i].id);
			}else{
				break;
			}
		}
	}
	return 0;
}