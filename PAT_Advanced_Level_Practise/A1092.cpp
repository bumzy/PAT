#include <cstdio>
#include <cstring>

int count[128] = {0};

int main(){
	char str1[1010], str2[1010];
	scanf("%s%s", str1, str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len1; ++i){
		++count[str1[i]];
	}
	int loss = 0;
	for(int i = 0; i < len2; ++i){
		--count[str2[i]];
		if(count[str2[i]] < 0)
			++loss;
	}
	if(loss > 0)
		printf("No %d", loss);
	else
		printf("Yes %d", len1 -len2);
	return 0;
}