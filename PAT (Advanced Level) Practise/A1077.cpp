#include <cstdio>
//#include <algorithm>
#include <cstring>
using namespace std;

char lines[110][260];

void reverse(char s[]){
	int len = strlen(s);
	for(int i = 0; i < len/2; ++i){
		char tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}
}

int main(){
	int N;
	scanf("%d", &N);
	getchar();
	int min = 257;
	for(int i = 0; i < N; ++i){
		gets(lines[i]);
		int len = strlen(lines[i]);
		if(len < min)
			min = len;
		reverse(lines[i]);
	}
	int cnt = 0;
	for(int i = 0; i < min; ++i){
		bool flag = true;
		for(int j = 1; j < N; ++j){
			if(lines[j][i] != lines[0][i])
				flag = false;
		}
		if(flag == true)
			++cnt;
		else
			break;
	}
	if(cnt == 0)
		printf("nai");
	else for(int i = cnt - 1; i >=0; --i){
		//if(lines[0][i] == ' ') continue;
		printf("%c", lines[0][i]);
	}
	return 0;
}