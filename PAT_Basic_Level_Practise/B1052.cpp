#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> express[3];

int main(){
	string str;
	for(int i = 0; i < 3; ++i){
		getline(cin, str);
		int j = 0;
		while(j < str.length()){
			if(str[j] == '['){
				++j;
				string temp;
				while(str[j] != ']' && j < str.length()){
					temp += str[j];
					++j;
				}
				if(str[j] == ']')
					express[i].push_back(temp);
			}
			++j;
		}
	}
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i){
		string ans;
		bool flag = true;
		for(int j = 0; j < 5; ++j){
			int t;
			cin >> t;
			if(j == 0 || j == 4){
				if(t <= express[0].size() && t >= 1){
					ans += express[0][t-1];
				}else{
					flag = false;
				}
				if(j == 0) ans += '(';
			}
			if(j == 1 || j == 3){
				if(t <= express[1].size() && t >= 1){
					ans += express[1][t-1];
				}else{
					flag = false;
				}
				if(j == 3) ans += ')';
			}
			if(j == 2){
				if(t <= express[2].size() && t >= 1){
					ans += express[2][t-1];
				}else{
					flag = false;
				}
			}
		}
		if(flag == false){
			cout << "Are you kidding me? @\\/@" << endl;
		}else{
			cout << ans << endl;
		}
	}
	return 0;
}