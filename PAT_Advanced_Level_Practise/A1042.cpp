#include <cstdio>
#include <string>
//#include <cstdlib>
using namespace std;

int n;
string cards[54];
string result[54];
int pos[54];
string type[4] = {"S", "H", "C", "D"};

void shuffle(){
	for(int i = 0; i < 54; ++i){
		result[pos[i]-1] = cards[i];
	}
	for(int i = 0; i < 54; ++i){
		cards[i] = result[i];
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 13; ++j){
			char buf[10];
			sprintf(buf, "%d", j + 1);
			cards[i*13+j] = type[i] + buf;
		}
	}
	cards[52] = "J1";
	cards[53] = "J2";
	for(int i = 0; i < 54; ++i){
		scanf("%d", &pos[i]);
	}
	while(n--) shuffle();
	for (int i = 0; i < 54; ++i){
		printf("%s", result[i].c_str());
		if(i != 53) printf(" ");
	}
	return 0;
}