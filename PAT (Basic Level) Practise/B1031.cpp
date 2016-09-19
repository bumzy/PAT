#include <cstdio>

const int W[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main(){
	char id[40];
	int n;
	scanf("%d", &n);
	bool all = true;
	while(n--){
		scanf("%s", id);
		int sum = 0;
		for(int i = 0; i < 17; ++i){
			sum += (id[i] - '0') * W[i];
		}
		if(M[sum % 11] != id[17]){
			printf("%s\n", id);
			all = false;
		}
	}
	if(all == true){
		printf("All passed\n");
	}
	return 0;
}