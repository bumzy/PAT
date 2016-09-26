#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 40000 + 10;
const int MAXK = 2500 + 10;
char name[MAXN][5];
vector<int> course[MAXK];

bool cmp(int a, int b){
	return strcmp(name[a], name[b]) < 0;
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%s", name[i]);
		int t;
		scanf("%d", &t);
		for(int j = 0; j < t; ++j){
			int c;
			scanf("%d", &c);
			course[c].push_back(i);
		}
	}
	for(int i = 1; i <= k; ++i){
		printf("%d %lu\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for(int j = 0; j < course[i].size(); ++j){
			printf("%s\n", name[course[i][j]]);
		}
	}
	return 0;
}