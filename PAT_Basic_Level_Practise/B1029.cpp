#include <cstdio>
#include <cstring>
using namespace std;

bool hashTable[256] = {false};
bool isPrint[256] = {false};

int main(){
	char str1[88], str2[88];
	scanf("%s%s", str1, str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len2; ++i){
		if(str2[i] >= 'a' && str2[i] <= 'z'){
			str2[i] = str2[i] - 'a' + 'A';
		}
		hashTable[str2[i]] = true;
	}
	for(int i = 0; i < len1; ++i){
		if(str1[i] >= 'a' && str1[i] <= 'z'){
			str1[i] = str1[i] - 'a' + 'A';
		}
		if(hashTable[str1[i]] == false && isPrint[str1[i]] == false){
			printf("%c", str1[i]);
			isPrint[str1[i]] = true;
		}
	}
	return 0;
}