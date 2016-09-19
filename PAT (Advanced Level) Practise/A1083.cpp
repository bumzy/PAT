#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Student{
	char name[12];
	char id[12];
	int grade;
} stu[110];

bool cmp(const Student &s1, const Student &s2){
	return s1.grade > s2.grade;
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].grade);
	}
	sort(stu, stu + N, cmp);
	int low, top;
	scanf("%d%d", &low, &top);
	bool flag = false;
	for(int i = 0; i < N; ++i){
		if(stu[i].grade >= low && stu[i].grade <= top){
			flag = true;
			printf("%s %s\n", stu[i].name, stu[i].id);
		}
	}
	if(flag == false) printf("NONE");
	return 0;
}