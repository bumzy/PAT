#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1000 + 10;
int hashTable[256] = {0};

int main(){
	char str1[MAXN], str2[MAXN];
	scanf("%s%s", str1, str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len1; ++i){
		hashTable[str1[i]]++;
	}
	for(int i = 0; i < len2; ++i){
		hashTable[str2[i]]--;
	}
	int ans = 0;
	for(int i = 0; i < 256; ++i){
		if(hashTable[i] < 0) ans -= hashTable[i];
	}
	if(ans == 0){
		printf("Yes %d", len1-len2);
	}else{
		printf("No %d", ans);
	}
	return 0;
}