#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, K, M;
struct Player{
	int arriveTime, startTime, trainTime;
	bool isVIP;
} newPlayer;
vector<Player> player;

struct Table{
	int endTime, numServer;
	bool isVIP;
} table[110];

int convertTime(int h, int m, int s){
	return h * 3600 + m * 60 + s;
}

void printTime(int s){
	printf("%02d:%02d:%02d", s / 3600, s % 3600 / 60, s % 60);
}

bool cmpArriveTime(const Player& p1, const Player& p2){
	return p1.arriveTime < p2.arriveTime;
}

bool cmpStartTime(const Player& p1, const Player& p2){
	return p1.startTime < p2.startTime;
}

void nextVIPPlayer(int &VIPi){
	++VIPi;
	while(VIPi < player.size() && player[VIPi].isVIP == 0)
		++VIPi;
	if(VIPi == player.size())
		VIPi = -1;
}

int firstIdleTable(bool isVIP){
	int idx = -1, minEndTime = 0x3fffffff;
	for(int i = 1; i <= K; ++i){
		if(isVIP){
			if(table[i].isVIP == true && table[i].endTime < minEndTime){
				idx = i;
				minEndTime = table[i].endTime;
			}
		}else{
			if(table[i].endTime < minEndTime){
				idx = i;
				minEndTime = table[i].endTime;
			}
		}
	}
	return idx;
}

void allocTable(int i, int idx){
	player[i].startTime = max(table[idx].endTime, player[i].arriveTime);
	table[idx].endTime = player[i].startTime + player[i].trainTime;
	table[idx].numServer++;
}

int main(){
	scanf("%d", &N);
	int stTime = convertTime(8, 0, 0);
	int edTime = convertTime(21, 0, 0);
	for(int i = 0; i < N; ++i){
		int h, m, s, trainTime, isVIP;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &trainTime, &isVIP);
		newPlayer.arriveTime = convertTime(h, m, s);
		if(newPlayer.arriveTime >= edTime) continue;
		newPlayer.startTime = edTime;
		newPlayer.trainTime = trainTime <= 120 ? trainTime * 60 : 7200;
		newPlayer.isVIP = isVIP;
		player.push_back(newPlayer);
	}
	scanf("%d%d", &K, &M);
	for(int i = 1; i <= K; ++i){
		table[i].numServer = table[i].isVIP = 0;
		table[i].endTime = stTime;
	}
	for(int i = 0; i < M; ++i){
		int VIPtable;
		scanf("%d", &VIPtable);
		table[VIPtable].isVIP = true;
	}
	sort(player.begin(), player.end(), cmpArriveTime);
	int i = 0, VIPi = -1;
	nextVIPPlayer(VIPi);
	while(i < player.size()){
		if(player[i].isVIP == 1 && i < VIPi){
			++i;
			continue;
		}
		int idx = firstIdleTable(false);
		if(table[idx].endTime >= edTime) break;
		if(table[idx].isVIP == true){
			if(player[i].isVIP == true){
				allocTable(i, idx);
				if(VIPi == i) nextVIPPlayer(VIPi);
				++i;
			}else{
				if(VIPi != -1 && player[VIPi].arriveTime <= table[idx].endTime){
					allocTable(VIPi, idx);
					nextVIPPlayer(VIPi);
				}else{
					allocTable(i, idx);
					++i;
				}
			}
		}else{
			if(player[i].isVIP == false){
				allocTable(i, idx);
				++i; 
			}else{
				int VIPidx = firstIdleTable(true);
				if(VIPidx != -1 && player[i].arriveTime >= table[VIPidx].endTime){
					allocTable(i, VIPidx);
					if(VIPi == i) nextVIPPlayer(VIPi);
					++i;
				}else{
					allocTable(i, idx);
					if(VIPi == i) nextVIPPlayer(VIPi);
					++i;
				}
			}
		}
	}
	sort(player.begin(), player.end(), cmpStartTime);
	for(int i = 0; i < player.size() && player[i].startTime < edTime; ++i){
		printTime(player[i].arriveTime);
		printf(" ");
		printTime(player[i].startTime);
		printf(" %.0f\n", round((player[i].startTime - player[i].arriveTime) / 60.0));
	}
	for(int i = 1; i <= K; ++i){
		if(i != 1) printf(" ");
		printf("%d", table[i].numServer);
	}
	printf("\n");
	return 0;
}