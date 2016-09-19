#include <iostream>
#include <string>
#include <map>
using namespace std;

bool check(const char &c){
	if(c >= '0' && c <= '9') return true;
	else if(c >= 'A' && c <='Z') return true;
	else if(c >= 'a' && c <='z') return true;
	return false;
}

int main(){
	map<string, int> cnt;
	string str;
	getline(cin, str);
	int i = 0;
	while(i < str.length()){
		string word;
		while(i < str.length() && check(str[i]) == true){
			word += tolower(str[i]);
			++i;
		}
		if(word.length() > 0){
			++cnt[word];
		}
		while(i < str.length() && check(str[i]) == false){
			++i;
		}
	}
	string ans;
	int max = 0;
	for(map<string, int>::iterator it = cnt.begin(); it != cnt.end(); ++it){
		if(it->second > max){
			ans = it->first;
			max = it->second;
		}
	}
	cout << ans << " " << max;
	return 0;
}