#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

map<string, vector<string> > index[6];

int main(){
	int N, M;
	cin >> N;
	cin.get();
	for(int i = 0; i < N; ++i){
		string id;
		getline(cin, id);
		for(int j = 1; j <= 5; ++j){
			string str;
			getline(cin, str);
			if(j != 3){
				index[j][str].push_back(id);
			}else{
				stringstream ss(str);
				string keyword;
				while(ss >> keyword){
					index[j][keyword].push_back(id);
				}
			}
		}
	}
	cin >> M;
	cin.get();
	for(int i = 0; i < M; ++i){
		string str;
		getline(cin, str);
		cout << str << endl;
		int type = str[0] - '0';
		string query = str.substr(3);
		if(index[type].find(query) != index[type].end()){
			sort(index[type][query].begin(), index[type][query].end());
			for(int j = 0; j < index[type][query].size(); ++j){
				cout << index[type][query][j] << endl;
			}
		}else{
			cout << "Not Found" << endl;
		}
	}
	return 0;
}