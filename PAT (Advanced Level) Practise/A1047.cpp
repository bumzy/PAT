#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> stu[2505];

int main(){
	int n, k;
	char name[5];
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i){
		int t;
		scanf("%s%d", name, &t);
		for(int j = 0; j < t; ++j){
			int c;
			scanf("%d", &c);
			stu[c].push_back(string(name));
		}
	}
	for(int i = 1; i <= k; ++i){
		printf("%d %lu\n", i, stu[i].size());
		sort(stu[i].begin(), stu[i].end());
		for(int j = 0; j < stu[i].size(); ++j){
			printf("%s\n", stu[i][j].c_str());
		}
	}
	return 0;
}