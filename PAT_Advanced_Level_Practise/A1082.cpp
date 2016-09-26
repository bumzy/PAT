#include <cstdio>
#include <cstring>

const char NUM[10][8] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
const char WEI[][8] = {"Shi","Bai","Qian","Wan","Yi"};

int cnt = 0;

int main(){
	char s[12];
	gets(s);
	int len = strlen(s);
	int left = 0, right = len - 1;
	if(s[0] == '-'){
		printf("Fu");
		++left;
	}
	while(right >= left + 4){
		right -= 4;
	}
	while(left < len){
		bool flag = false;
		bool isPrint = false;
		while(left <= right){
			if(left > 0 && s[left] == '0'){
				flag = true;
			}else{
				if(flag == true){
					printf(" ling");
					flag = false;
				}
				if(left > 0) printf(" ");
				printf("%s", NUM[s[left] - '0']);
				isPrint = true;
				if(left != right){
					printf(" %s", WEI[right - left - 1]);
				}
			}
			++left;
		}
		if(isPrint == true && right != len - 1){
			printf(" %s", WEI[(len - 1 -right) / 4 + 2]);
		}
		right += 4;
	}
	return 0;
}