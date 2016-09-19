#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 10000 + 10;
struct Car{
	char id[8];
	int time;
	bool status;
} all[MAXN], valid[MAXN];

int N, K;
map<string, int> parkTime;

int timeToInt(int hh, int mm, int ss){
	return hh * 3600 + mm * 60 + ss;
}

bool cmpByIdAndTime(const Car &c1, const Car &c2){
	if(strcmp(c1.id, c2.id) != 0) return strcmp(c1.id, c2.id) < 0;
	else return c1.time < c2.time;
}

bool cmpByTime(const Car &c1, const Car &c2){
	return c1.time < c2.time;
}

int main(){
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; ++i){
		char in_out[8];
		int hh, mm, ss;
		scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, in_out);
		all[i].time = timeToInt(hh, mm, ss);
		all[i].status = in_out[0] == 'i'? true : false;
	}
	sort(all, all + N, cmpByIdAndTime);
	int num = 0;
	int maxTime = -1;
	for(int i = 0; i < N-1; ++i){
		if(strcmp(all[i].id, all[i+1].id) == 0 && 
			all[i].status == true && 
			all[i+1].status == false){
			valid[num++] = all[i];
			valid[num++] = all[i+1];
			int inTime = all[i+1].time - all[i].time;
			parkTime[all[i].id] += inTime;
			maxTime = max(maxTime, parkTime[all[i].id]);
		}
	}
	sort(valid, valid + num, cmpByTime);
	int now = 0, cnt = 0;
	for(int i = 0; i < K; ++i){
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int time = timeToInt(hh, mm, ss);
		while(now < num && valid[now].time <= time){
			if(valid[now].status == true) ++cnt;
			else --cnt;
			++now;
		}
		printf("%d\n", cnt);
	}
	map<string, int>::iterator it;
	for(it = parkTime.begin(); it != parkTime.end(); ++it){
		if(it->second == maxTime){
			printf("%s ", it->first.c_str());
		}
	}
	printf("%02d:%02d:%02d", maxTime/3600, maxTime%3600/60, maxTime%60);
	return 0;
}