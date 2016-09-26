#include <cstdio>
#include <cstring>
using namespace std;

int count[128] = {0};
char ch[6] = {'P', 'A', 'T', 'e', 's', 't'};

int main(){
	char str[10010];
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; ++i){
		++count[str[i]];
	}
	while(true){
		bool flag = true;
		for(int i = 0; i < 6; ++i){
			if(count[ch[i]] > 0){
				printf("%c", ch[i]);
				flag = false;
				--count[ch[i]];
			}
		}
		if(flag) break;
	}
	return 0;
}