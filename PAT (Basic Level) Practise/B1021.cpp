#include <cstdio>
#include <cstring>
using namespace std;

int cnt[10] = {0};

int main(){
	char str[1010];
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; ++i){
		int digit = str[i] - '0';
		++cnt[digit];
	}
	for(int i = 0; i < 10; ++i){
		if(cnt[i] != 0){
			printf("%d:%d\n", i, cnt[i]);
		}
	}
	return 0;
}