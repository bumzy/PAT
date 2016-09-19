#include <cstdio>
#include <cctype>
#include <cstring>

bool mark[256] = {false};

int main(){
	char origin[100], typed[100];
	scanf("%s%s", origin, typed);
	int len1 = strlen(origin);
	int len2 = strlen(typed);
	int i = 0, j = 0;
	while(i < len1){
		if(toupper(origin[i]) == toupper(typed[j])){
			++i;
			++j;
		}else{
			char tmp = toupper(origin[i]);
			if(mark[tmp] == false){
				mark[tmp] = true;
				printf("%c", tmp);
			}
			++i;
		}
	}
	return 0;
}