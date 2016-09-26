#include <cstdio>
#include <cstring>
#include <cstdlib>
//using namespace std;
struct Student{
	char name[16];
	char gender[4];
	char id[16];
	int score;
	Student() : score(0){}
	Student(int s) : score(s){}
	bool operator < (const Student &s) const{
		return score < s.score;
	}
	bool operator > (const Student &s) const{
		return score > s.score;
	}
	/**Student &operator = (const Student &s){
		strcpy(name, s.name);
		strcpy(gender, s.gender);
		strcpy(id, s.id);
		score = s.score;
		return *this;
	}**/
};

int main(){
	int n;
	scanf("%d", &n);
	Student tmp, lowest_male(101), highest_female(-1);
	bool flag1 = false, flag2 = false;
	while(n--){
		scanf("%s%s%s%d", tmp.name, tmp.gender, tmp.id, &tmp.score);
		if(tmp.gender[0] == 'M'){
			flag1 = true;
			if(tmp < lowest_male){
				lowest_male = tmp;
			}
		}else{
			flag2 = true;
			if(tmp > highest_female){
				highest_female = tmp;
			}
		}
	}

	if(flag2)
		printf("%s %s\n", highest_female.name, highest_female.id);
	else
		printf("Absent\n");

	if(flag1)
		printf("%s %s\n", lowest_male.name, lowest_male.id);
	else
		printf("Absent\n");

	if(flag1 && flag2)
		printf("%d", abs(highest_female.score - lowest_male.score));
	else
		printf("NA");
	return 0;
}