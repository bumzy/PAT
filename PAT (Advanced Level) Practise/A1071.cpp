#include <iostream>
#include <map>
#include <algorithm>
//#include <cctype>
using namespace std;

map<string, int> cnt;

int main(){
	string str;
	while(cin >> str){
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		while(!str.empty() && !isalpha(*str.begin()) && !isdigit(*str.begin())){
			str.erase(str.begin());
		}
		while(!str.empty() && !isalpha(*(str.end()-1)) && !isdigit(*(str.end()-1))){
			str.erase(str.end()-1);
		}
		if(!str.empty())
			++cnt[str];
	}
	int max = -1;
	map<string, int>::iterator it;
	for(it = cnt.begin(); it != cnt.end(); ++it){
		if(it->second > max){
			str = it->first;
			max = it->second;
		}
	}
	cout << str << " " << max;
	return 0;
}