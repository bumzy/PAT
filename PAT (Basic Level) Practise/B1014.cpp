#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

const char DAY[8][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main(){
	char a1[62], a2[62], b1[62], b2[62];
	scanf("%s%s%s%s", a1, a2, b1, b2);
	int len_a = min(strlen(a1), strlen(a2));
	int len_b = min(strlen(b1), strlen(b2));
	int i = 0;
	for( ; i < len_a; ++i){
		if(a1[i] == a2[i] && a1[i] >= 'A' && a1[i] <= 'G'){
			printf("%s ", DAY[a1[i]-'A']);
			break;
		}
	}
	for(int j = i+1; j < len_a; ++j){
		if(a1[j] == a2[j]){
			int hh = 0;
			if(a1[j] >= 'A' && a1[j] <= 'N'){
				hh = a1[j] - 'A' + 10;
				printf("%02d:", hh);
				break;
			}else if(a1[j] >= '0' && a1[j] <= '9'){
				hh = a1[j] - '0';
				printf("%02d:", hh);
				break;
			}
		}
	}
	for(int j = 0; j < len_b; ++j){
		if(b1[j] == b2[j] && isalpha(b1[j])){
			printf("%02d", j);
			break;
		}
	}
	return 0;
}