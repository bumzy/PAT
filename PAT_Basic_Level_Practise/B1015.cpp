#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int N, L, H;
struct Student{
	int id, de, cai, total, type;
} stu[MAXN];

bool cmp(const Student &s1, const Student &s2){
	if(s1.type != s2.type) return s1.type > s2.type;
	else if(s1.total != s2.total) return s1.total > s2.total;
	else if(s1.de != s2.de) return s1.de > s2.de;
	else return s1.id < s2.id;
}

int main(){
	scanf("%d%d%d", &N, &L, &H);
	int cnt = 0;
	for(int i = 0; i < N; ++i){
		int id, de, cai, type;
		scanf("%d%d%d", &id, &de, &cai);
		if(de >= L && cai >= L){
			if(de >= H && cai >= H){
				type = 4;
			}else if(de >= H){
				type = 3;
			}else if(de >= cai){
				type = 2;
			}else{
				type = 1;
			}
			stu[cnt].type = type;
			stu[cnt].id = id;
			stu[cnt].de = de;
			stu[cnt].cai = cai;
			stu[cnt++].total = de + cai;
		}
	}
	sort(stu, stu+cnt, cmp);
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; ++i){
		printf("%08d %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
	}
	return 0;
}