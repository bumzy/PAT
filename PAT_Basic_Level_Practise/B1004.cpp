#include <cstdio>
#include <map>
using namespace std;

struct student{
	char name[20];
	char id[20];
};

map<int, student> score;

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		//char name[20], id[20];
		int s;
		student stu;
		scanf("%s%s%d", stu.name, stu.id, &s);
		score[s] = stu;
	}
	map<int, student>::iterator it = --score.end();
	printf("%s %s\n", (it->second).name, (it->second).id);
	it = score.begin();
	printf("%s %s", (it->second).name, (it->second).id);
	return 0;
}