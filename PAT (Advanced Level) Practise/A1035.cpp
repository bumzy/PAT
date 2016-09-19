#include <cstdio>
#include <cstring>

int cnt = 0;
char pass[1010][16];
char name[1010][16];
int ans[1010];

bool replace_pass(char s[]){
	bool flag = false;
	int len = strlen(s);
	for(int i = 0; i < len; ++i){
		if(s[i] == '1'){
			s[i] = '@';
			flag = true;
		}else if(s[i] == '0'){
			s[i] = '%';
			flag = true;
		}else if(s[i] == 'l'){
			s[i] = 'L';
			flag = true;
		}else if(s[i] == 'O'){
			s[i] = 'o';
			flag = true;
		}
	}
	return flag;
}
int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%s%s", name[i], pass[i]);
		if(replace_pass(pass[i])){
			ans[cnt++] = i;
		}
	}
	if(cnt > 0){
		printf("%d\n", cnt);
		for(int i = 0; i < cnt; ++i){
			printf("%s %s\n", name[ans[i]], pass[ans[i]]);
		}
	}else{
		if(N > 1)
			printf("There are %d accounts and no account is modified", N);
		else
			printf("There is 1 account and no account is modified");
	}
	return 0;
}