#include <string>
#include <iostream>
#include <map>
using namespace std;

int N;
const string low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const string high[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> strToInt;
map<int, string> intToStr;

void init(){
	for(int i = 0; i < 13; ++i){
		strToInt[low[i]] = i;
		strToInt[high[i]]= i * 13;
		intToStr[i] = low[i];
		intToStr[i*13] = high[i];
	}
	for(int i = 1; i < 13; ++i){
		for(int j = 1; j < 13; ++j){
			string temp = high[i] + " " + low[j];
			strToInt[temp] = i*13 + j;
			intToStr[i*13+j] = temp;
		}
	}
}

int transfer(const string &str){
	int num = 0;
	for(int i = 0; i < str.length(); ++i){
		num = num * 10 + str[i] - '0';
	}
	return num;
}

int main(){
	init();
	int num;
	string str;
	cin >> N;
	getline(cin, str);
	for(int i = 0; i < N; ++i){
		getline(cin, str);
		if(str[0] >= '0' && str[0] <= '9'){
			num = transfer(str);
			cout << intToStr[num] << endl;
		}else{
			cout << strToInt[str] << endl;
		}
	}
	return 0;
}