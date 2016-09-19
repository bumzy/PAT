#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

set<int> st[51];

void compare(int x, int y){
	int sameNum = 0, totalNum = st[x].size();
	for(set<int>::iterator it = st[y].begin(); it != st[y].end(); ++it){
		if(st[x].find(*it) != st[x].end()) ++sameNum;
		else ++totalNum;
	}
	printf("%.1f%%\n", sameNum * 100.0 / totalNum);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int m;
		scanf("%d", &m);
		for(int j = 0; j < m; ++j){
			int x;
			scanf("%d", &x);
			st[i].insert(x);
		}
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		compare(x, y);
	}
	return 0;
}