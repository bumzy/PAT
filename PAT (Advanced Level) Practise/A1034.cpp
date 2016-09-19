#include <iostream>
#include <map>
#include <string>
using namespace std;

const int MAXN = 2000 + 10;
int G[MAXN][MAXN] = {0}, weight[MAXN] = {0};
bool visited[MAXN]= {false};
int N, K, numPersion = 0;
map<int, string> intToStringMap;
map<string, int> stringToIntMap;
map<string, int> Gang;

int stringToInt(string str){
	if(stringToIntMap.find(str) != stringToIntMap.end()){
		return stringToIntMap[str];
	}else{
		stringToIntMap[str] = numPersion;
		intToStringMap[numPersion] = str;
		return numPersion++;
	}
}

void DFS(int nowVisit, int &head, int &numMember, int &totalWeight){
	++numMember;
	visited[nowVisit] = true;
	if(weight[nowVisit] > weight[head]){
		head = nowVisit;
	}
	for(int i = 0; i < numPersion; ++i){
		if(G[nowVisit][i] > 0){
			totalWeight += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if(visited[i] == false)
				DFS(i, head, numMember, totalWeight);
		}
	}
}

void DFSTrave(){
	for(int i = 0; i < numPersion; ++i){
		if(visited[i] == false){
			int head = i, numMember = 0, totalWeight = 0;
			DFS(i, head, numMember, totalWeight);
			if(numMember > 2 && totalWeight > K){
				Gang[intToStringMap[head]] = numMember;
			}
		}
	}
}

int main(){
	cin >> N >> K;
	string str1, str2;
	int w;
	for(int i = 0; i < N; ++i){
		cin >> str1 >> str2 >> w;
		int id1 = stringToInt(str1);
		int id2 = stringToInt(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFSTrave();
	cout << Gang.size() << endl;
	for(map<string, int>::iterator it = Gang.begin(); it != Gang.end(); ++it){
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}