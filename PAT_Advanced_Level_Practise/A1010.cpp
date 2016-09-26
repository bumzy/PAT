#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long INF = (1LL << 63) - 1;
struct Number{
	char digit[12];
	int radix;
	int minRadix(){
		int max = -1;
		int len = strlen(digit);
		for(int i = 0; i < len; ++i){
			int tmp;
			if(digit[i] >= '0' && digit[i] <= '9'){
				tmp = digit[i] - '0';
			}else{
				tmp = digit[i] - 'a' + 10;
			}
			if(tmp > max){
				max = tmp;
			}
		}
		return max + 1;
	}
	long long decimal(){
		long long ans = 0;
		long long weight = 1;
		int len = strlen(digit);
		for(int i = len - 1; i >= 0; --i){
			int tmp;
			if(digit[i] >= '0' && digit[i] <= '9'){
				tmp = digit[i] - '0';
			}else{
				tmp = digit[i] - 'a' + 10;
			}
			ans += tmp * weight;
			weight *= radix;
			if(ans < 0) return -1;
		}
		return ans;
	}
} num1, num2;

int binarySearch(){
	long long x = num1.decimal();
	long long left = num2.minRadix(), right = max(left, x) + 1, mid;
	while(left <= right){
		mid = (left + right) / 2;
		num2.radix = mid;
		if(num2.decimal() == x) return mid;
		if(num2.decimal() < 0 || num2.decimal() > x){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	return -1;
}

int main(){
	scanf("%s%s", num1.digit, num2.digit);
	int flag, radix;
	scanf("%d%d", &flag, &radix);
	if(flag == 2){
		swap(num1.digit, num2.digit);
	}
	num1.radix = radix;
	int ans = binarySearch();
	if(ans == -1) printf("Impossible");
	else printf("%d", ans);
}