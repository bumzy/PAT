#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Person{
	char name[12];
	int age, worth, status;
} men[100010];

int N, K, M, Amin, Amax;

bool cmp(const Person & p1, const Person & p2){
	if(p1.worth != p2.worth) return p1.worth > p2.worth;
	else if(p1.age != p2.age) return p1.age < p2.age;
	else return strcmp(p1.name, p2.name) < 0;
}

int main(){
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; ++i){
		scanf("%s%d%d", men[i].name, &men[i].age, &men[i].worth);
	}
	sort(men, men + N, cmp);
	for(int i = 1; i <= K; ++i){
		scanf("%d%d%d", &M, &Amin, &Amax);
		printf("Case #%d:\n", i);
		int cnt = 0;
		for(int j = 0; j < N && cnt < M; ++j){
			if(men[j].age >= Amin && men[j].age <= Amax){
				printf("%s %d %d\n", men[j].name, men[j].age, men[j].worth);
				++cnt;
			}
		}
		if(cnt == 0)
			printf("None\n");
	}
	return 0;
}