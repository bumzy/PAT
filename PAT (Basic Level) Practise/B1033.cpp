#include <cstdio>
#include <cstring>
#include <cctype>

const int MAXN = 100000 + 10;
bool mark[128];

int main(){
	memset(mark, true, sizeof(mark));
	char bad[MAXN], type[MAXN];
	//scanf("%s%s", bad, type);
	//first line may be empty
	gets(bad);
	gets(type);
	int len1 = strlen(bad);
	int len2 = strlen(type);
	for(int i = 0; i < len1; ++i){
		if(bad[i] == '+'){
			for(char j = 'A'; j <= 'Z'; ++j){
				mark[j] = false;
			}
		}else if(isalpha(bad[i])){
			mark[bad[i]] = false;
			mark[tolower(bad[i])] = false;
		}else{
			mark[bad[i]] = false;
		}
	}
	for(int i = 0; i < len2; ++i){
		if(mark[type[i]] == true)
			printf("%c", type[i]);
	}
	printf("\n");
	return 0;
}