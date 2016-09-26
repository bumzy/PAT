#include <cstdio>
#include <map>
using namespace std;

map<int, int> count;

int main(){
	int M, N;
	scanf("%d%d", &M, &N);
	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			int pixel;
			scanf("%d", &pixel);
			++count[pixel];
		}
	}
	for(map<int, int>::iterator it = count.begin(); it != count.end(); ++it){
		if(it->second > M * N / 2){
			printf("%d\n", it->first);
			break;
		}
	}
	return 0;
}