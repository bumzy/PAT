#include <cstdio>
#include <cstring>
using namespace std;

int cnt = 0, N;
double sum = 0.0;

bool judge(char str[]){
	double temp = 0.0;
	int len = strlen(str);
	int start, flag = -1;
	int sign = 1;
	if(str[0] == '-'){
		start = 1;
		sign = -1;
	}else{
		start = 0;
	}
	for(int i = start; i < len; ++i){
		if(str[i] >= '0' && str[i] <= '9'){
			continue;
		}else if(str[i] == '.' && flag == -1){
			flag = i;
		}else{
			return false;
		}
	}
	if(flag == -1){
		for(int i = start; i < len; ++i){
			temp = temp * 10 + str[i] - '0';
		}
	}else{
		if(len - flag - 1 > 2) return false;
		for(int i = start; i < flag; ++i){
			temp = temp * 10 + str[i] - '0';
		}
		double w = 1;
		for(int i = flag + 1; i < len; ++i){
			w /= 10;
			temp += (str[i] - '0') * w;
		}
	}
	temp *= sign;
	if(temp < -1000 || temp > 1000) return false;
	++cnt;
	sum += temp;
	//printf("%lf\n", temp);
	return true;
}

int main(){
	char str[1024];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%s", str);
		if(!judge(str)){
			printf("ERROR: %s is not a legal number\n", str);
		}
	}
	if(cnt == 0){
		printf("The average of 0 numbers is Undefined\n");
	}else if(cnt == 1){
		printf("The average of %d number is %.2lf\n", cnt, sum);
	}else{
		printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);
	}
	return 0;
}