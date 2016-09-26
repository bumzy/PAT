#include <cstdio>
#include <cstring>
using namespace std;

struct Number{
	int digit[110];
	int exp, len;
	Number() : exp(0), len(0) {
		memset(digit, 0, sizeof(digit));
	}
} a, b;

Number transfer(char str[]){
	Number a;
	int len = strlen(str);
	bool flag = true;
	int i = 0;
	while(str[i] == '0' && i < len) ++i;
	if(i == len) return a;
	if(str[i] == '.'){
		++i;
		while(str[i] == '0' && i < len){
			--a.exp;
			++i;
		}
		if(i == len) a.exp = 0;
		else{
			while(i < len){
				a.digit[a.len++] = str[i++] - '0';
			}
		}
	}else{
		while(i < len){
			if(str[i] != '.'){
				a.digit[a.len++] = str[i] - '0';
				if(flag == true)
					++a.exp;
			}else{
				flag = false;
			}
			++i;
		}
	}
	return a;
}

bool compare(int n, const Number &n1, const Number &n2){
	if(n1.exp != n2.exp) return false;
	for(int i = 0; i < n; ++i){
		if(n1.digit[i] != n2.digit[i]) return false;
	}
	return true;
}

void print(int n, const Number &num){
	printf("0.");
	for(int i = 0; i < n; ++i){
		printf("%d", num.digit[i]);
	}
	printf("*10^%d", num.exp);
}

int main(){
	int n;
	char str1[110], str2[110];
	scanf("%d%s%s", &n, str1, str2);
	a = transfer(str1);
	b = transfer(str2);
	if(compare(n, a, b)){
		printf("YES ");
		print(n, a);
	}else{
		printf("NO ");
		print(n, a);
		printf(" ");
		print(n, b);
	}
	return 0;
}