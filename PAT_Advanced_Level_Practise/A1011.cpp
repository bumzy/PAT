#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	double odds[3];
	char names[3] = {'W', 'T', 'L'};
	double result = 0.65;
	while(scanf("%lf%lf%lf", &odds[0], &odds[1], &odds[2]) != EOF){
		int idx;
		double max = 0;
		for(int i = 0; i < 3; ++i){
			if(odds[i] > max){
				max = odds[i];
				idx = i;
			}
		}
		result *= max;
		printf("%c ", names[idx]);
	}
	printf("%.2f", (result-1.0)*2.0);
	return 0;
}