#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool judge(char str[], int a, int b){
	while(a < b){
		if(str[a] != str[b]){
			return false;
		}
		++a;
		--b;
	}
	return true;
}
int main(){
	char str[1010];
	gets(str);
	int len = strlen(str);
	int ans = 1;
	for(int i = 0; i < len; ++i){
		for(int j = 1; j < len; ++j){
			if(i-j >= 0 && i+j < len && judge(str, i-j, i+j))
				ans = max(ans, j*2 + 1);
			if(i-j+1 >= 0 && i+j < len && judge(str, i-j+1, i+j))
				ans = max(ans, j*2);
		}
	}
	printf("%d", ans);
	return 0;
}