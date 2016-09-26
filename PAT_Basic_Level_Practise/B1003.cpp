#include <cstdio>
#include <cstring>

bool judge(char s[], int len){
	int posP = -1, posT = -1, midA = 0;
	for(int i = 0; i < len; ++i){
		if(s[i] == 'A'){
			if(posP != -1 && posT == -1){
				++midA;
			}
		}else if(s[i] == 'P' && posP == -1){
			posP = i;
		}else if(s[i] == 'T' && posT == -1){
			posT = i;
		}else{
			return false;
		}
	}
	/*if(posP == -1 || posT == -1 || midA == 0) return false;
	if(posT - posP + 1 == 3 && posP == len - 1 - posT) return true;
	//int midA = posT - posP - 2;
	//if(posT - midA < 0) return false;
	s[posT] = 'A';
	s[posT-1] = 'T';
	len -= (posP + 1) * 1;
	if(len < 3) return false;
	return judge(s, len);*/
	int x = posP, y = posT - posP - 1, z = len - posT - 1;
	if(z-x*(y-1) == x && y > 0){
		return true;
	}else{
		return false;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		char s[110];
		scanf("%s", s);
		int len = strlen(s);
		if(judge(s, len)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}