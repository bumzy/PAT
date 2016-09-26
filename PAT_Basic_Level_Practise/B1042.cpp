#include <cstdio>
#include <cstring>
#include <cctype>

int count[26] = {0};

int main(){
	char str[1010];
	gets(str);
	int len = strlen(str);
	for(int i = 0; i < len; ++i){
		char c = tolower(str[i]);
		if(isalpha(c)){
			++count[c-'a'];
		}
	}
	int max = -1, idx = 0;
	for(int i = 0; i < 26; ++i){
		if(count[i] > max){
			idx = i;
			max = count[i];
		}
	}
	printf("%c %d", idx + 'a', max);
}