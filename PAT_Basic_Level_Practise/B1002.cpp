#include <cstdio>
#include <cstring>

const char PY[11][8] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main(){
	char n[110];
	scanf("%s", n);
	int len = strlen(n);
	int sum = 0;
	for(int i = 0; i < len; ++i){
		sum += n[i] - '0';
	}
	if(sum >= 100){
		printf("%s ", PY[sum / 100]);
	}
	if(sum >= 10){
		printf("%s ", PY[sum / 10 % 10]);
	}
	printf("%s", PY[sum % 10]);
	return 0;
}