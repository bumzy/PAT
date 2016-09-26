#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 10000 + 10;
int N, K;
struct Person{
	string name;
	int height;
} person[MAXN];

bool cmp(const Person &p1, const Person &p2){
	if(p1.height != p2.height) return p1.height < p2.height;
	else return p1.name > p2.name;
}

vector<string> ans[11];

int main(){
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; ++i){
		char name[8];
		int height;
		scanf("%s%d", name, &height);
		person[i].name = name;
		person[i].height = height;
	}
	sort(person, person+N, cmp);
	int num = N/K;
	for(int i = 0; i < K; ++i){
		bool flag = true;
		if(i != K-1){
			for(int j = (i+1)*num-1; j >= i*num; --j){
				if(flag == true){
					ans[i].push_back(person[j].name);
				}else{
					ans[i].insert(ans[i].begin(), person[j].name);
				}
				flag = !flag;
			}
		}else{
			for(int j = N-1; j >= i*num; --j){
				if(flag == true){
					ans[i].push_back(person[j].name);
				}else{
					ans[i].insert(ans[i].begin(), person[j].name);
				}
				flag = !flag;
			}
		}
	}
	for(int i = K-1; i >= 0; --i){
		for(int j = 0; j < ans[i].size(); ++j){
			if(j != 0) printf(" ");
			printf("%s", ans[i][j].c_str());
		}
		printf("\n");
	}
	return 0;
}