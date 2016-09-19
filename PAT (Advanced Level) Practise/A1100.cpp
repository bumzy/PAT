#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;

const string Bit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const string Ten[13] = {"*", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> M;

int to_number(char str[]){
	int result = 0;
	int len = strlen(str);
	for(int i = 0; i < len; ++i){
		result = result * 10 + str[i] - '0';
	}
	return result;
}

int main(){
	for(int i = 0; i < 13; ++i){
		M[Bit[i]] = i;
		M[Ten[i]] = i * 13;
	}
	int n;
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; ++i){
		char str[100];
		gets(str);
		if(str[0] >= '0' && str[0] <= '9'){
			int num = to_number(str);
			if(num / 13 != 0) printf("%s", Ten[num/13].c_str());
			if(num / 13 != 0 && num % 13 != 0) printf(" ");
			if(num % 13 != 0 || num == 0) printf("%s", Bit[num%13].c_str());
			printf("\n");
		}else{
			int ans = 0;
			string s(str);
			size_t pos = s.find(' ');
			if(pos == string::npos){
				printf("%d\n", M[s]);
			}else{
				printf("%d\n", M[s.substr(0, pos)]+M[s.substr(pos + 1)]);
			}
		}
	}
	return 0;
}