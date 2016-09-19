#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 10000 + 10;
string num[MAXN];

bool cmp(const string &s1, const string &s2){
	return s1 + s2 < s2 + s1;
}

int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> num[i];
	}
	sort(num, num + N, cmp);
	string ans;
	for(int i = 0; i < N; ++i){
		ans += num[i];
	}
	while(ans.size() != 0 && ans[0] == '0'){
		ans.erase(ans.begin());
	}
	if(ans.size() == 0) cout << 0;
	else cout << ans;
	return 0;
}