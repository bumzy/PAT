#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 40000 + 10;
struct Student{
	int id, Ge, Gi, sum, choice[10], rank;
	//bool admit;
} stu[MAXN];

bool cmp(const Student &s1, const Student &s2){
	if(s1.sum != s2.sum) return s1.sum > s2.sum;
	else return s1.Ge > s2.Ge;
}

int num[110] = {0};
int cnt[110] = {0};
int pree[110] = {0};
int prei[110] = {0};
int preid[110] = {0};
int result[110][MAXN] = {0};
int N, M, K;

int main(){
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 0; i < M; ++i){
		scanf("%d", &num[i]);
	}
	for(int i = 0; i < N; ++i){
		//stu[i].admit = false;
		scanf("%d%d", &stu[i].Ge, &stu[i].Gi);
		for(int j = 0; j < K; ++j){
			scanf("%d", &stu[i].choice[j]);
		}
		stu[i].sum = stu[i].Ge + stu[i].Gi;
		stu[i].id = i;
	}
	sort(stu, stu + N, cmp);
	stu[0].rank = 1;
	for(int i = 1; i < N; ++i){
		if(stu[i].sum == stu[i-1].sum && stu[i].Ge == stu[i-1].Ge ){
			stu[i].rank = stu[i-1].rank;
		}else{
			stu[i].rank = i + 1;
		}
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < K; ++j){
			int cho = stu[i].choice[j];
			//if(cnt[cho] < num[cho] || (cnt[cho] > 0 && stu[result[cho][cnt[cho]-1]].rank == stu[i].rank)){
			if(cnt[cho] < num[cho] || (cnt[cho] > 0 && pree[cho] == stu[i].Ge && prei[cho] == stu[i].Gi)){
			//if(cnt[cho] < num[cho] || (cnt[cho] > 0 && stu[preid[cho]].rank == stu[i].rank)){
				result[cho][cnt[cho]] = stu[i].id;
				pree[cho] = stu[i].Ge;
				prei[cho] = stu[i].Gi;
				preid[cho] = stu[i].id;
				//stu[i].admit = true;
				++cnt[cho];
				break;
			}
		}
	}
	for(int i = 0; i < M; ++i){
		if(cnt[i] > 0){
			sort(&result[i][0], &result[i][cnt[i]]);
			for(int j = 0; j < cnt[i]; ++j){
				if(j != 0) printf(" ");
				printf("%d", result[i][j]); 
			}
		}
		printf("\n");
	}
	return 0;
}