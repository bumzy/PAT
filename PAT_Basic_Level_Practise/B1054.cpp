#include <cstdio>
#include <cstring>
using namespace std;

int N, cnt = 0;
double sum = 0;

bool judge(char str[]){
	int point = -1;
	double num = 0;
	int len = strlen(str);
	int start = 0;
	if(str[0] == '-'){
		start = 1;
	}
	for(int i = start; i < len; ++i){
		if(str[i] >= '0' && str[i] <= '9'){
			continue;
		}else if(point == -1 && str[i] == '.'){
			point = i;
		}else{
			return false;
		}
	}
	if(point == -1){
		for(int i = start; i < len; ++i){
			num = num * 10 + str[i] - '0';
		}
	}else{
		if(len - point > 3) return false;
		for(int i = start; i < point; ++i){
			num = num * 10 + str[i] - '0';
		}
		double w = 1;
		for(int i = point + 1; i < len; ++i){
			w /= 10;
			num += (str[i] - '0') * w;
		}
	}
	if(start == 1) num *= -1;
	if(num < -1000 || num > 1000) return false;
	sum += num;
	++cnt;
	return true;
}

int main(){
	scanf("%d", &N);
	char str[1024];
	for(int i = 0; i < N; ++i){
		scanf("%s", str);
		double num;
		if(!judge(str)){
			printf("ERROR: %s is not a legal number\n", str);
		}
	}
	if(cnt == 0){
		printf("The average of 0 numbers is Undefined\n");
	}else if(cnt == 1){
		printf("The average of 1 number is %.2lf\n", sum);
	}else{
		printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);
	}
	return 0;
}