#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student{
	int id, score;
	char name[12];
} stu[100010];

int N, C;

bool cmp(const Student &s1, const Student &s2){
	if(C == 1){
		return s1.id < s2.id;
	}else if(C == 2){
		if(strcmp(s1.name, s2.name) != 0) return strcmp(s1.name, s2.name) < 0;
		else return s1.id < s2.id;
	}else{
		if(s1.score != s2.score) return s1.score < s2.score;
		else return s1.id < s2.id;
	}
}

int main(){
	scanf("%d%d", &N, &C);
	for(int i = 0; i < N; ++i){
		scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].score);
	}
	sort(stu, stu + N, cmp);
	for(int i = 0; i < N; ++i){
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
	}
	return 0;
}