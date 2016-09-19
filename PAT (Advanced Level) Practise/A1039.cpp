#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int M = 26*26*26*10 + 1;
vector<int> course[M];

int getID(char name[]){
	int id = 0;
	for(int i = 0; i < 3; ++i){
		id = id * 26 + (name[i] - 'A');
	}
	id = id*10 + (name[3] - '0');
	return id;
}

int main(){
	int n, k;
	char name[5];
	scanf("%d%d", &n, &k);
	for(int i = 0; i < k; ++i){
		int c, x;
		scanf("%d%d", &c, &x);
		for(int i = 0; i < x; ++i){
			scanf("%s", name);
			int id = getID(name);
			course[id].push_back(c);
		}
	}
	for(int i = 0; i < n; ++i){
		scanf("%s", name);
		int id = getID(name);
		sort(course[id].begin(), course[id].end());
		printf("%s %d", name, course[id].size());
		for(int j = 0; j < course[id].size(); ++j){
			printf(" %d", course[id][j]);
		}
		printf("\n");
	}
	return 0;
}