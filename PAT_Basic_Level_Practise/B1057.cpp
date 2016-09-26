#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100000 + 10;
char str[MAXN];

int main(){
	fgets(str, MAXN, stdin);
	int len = strlen(str);
	int sum = 0;
	for(int i = 0; i < len; ++i){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			sum += str[i] - 'A' + 1;
		}else if(str[i] >= 'a' && str[i] <= 'z'){
			sum += str[i] - 'a' + 1;
		}
	}
	int cnt0 = 0, cnt1 = 0;
	if(sum == 0){
		//cnt0 = 1;
	}else{
		while(sum != 0){
			if(sum % 2 == 0){
				++cnt0;
			}else{
				++cnt1;
			}
			sum /= 2;
		}
	}
	printf("%d %d", cnt0, cnt1);
	return 0;
}