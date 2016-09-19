#include <cstdio>
#include <cstring>

bool valid[128];

int main(){
	memset(valid, true, sizeof(valid));
	char str1[10010], str2[10010];
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len2; ++i){
		valid[str2[i]] = false;
	}
	for(int i = 0; i < len1; ++i){
		if(valid[str1[i]] == true){
			printf("%c", str1[i]);
		}
	}
	return 0;
}