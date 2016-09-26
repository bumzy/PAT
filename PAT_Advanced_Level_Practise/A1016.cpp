#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int cost[24];
struct Record{
	char name[24];
	int dd, hh, mm;
	bool on_off;
} recs[1010];

bool cmp(const Record &r1, const Record &r2){
	if(strcmp(r1.name, r2.name) != 0) return strcmp(r1.name, r2.name) < 0;
	else if(r1.dd != r2.dd) return r1.dd < r2.dd;
	else if(r1.hh != r2.hh) return r1.hh < r2.hh;
	else if(r1.mm != r2.mm) return r1.mm < r2.mm;
}

void get_time_money(int on, int off, int &time, int &money){
	Record tmp = recs[on];
	while(tmp.dd < recs[off].dd || tmp.hh < recs[off].hh || tmp.mm < recs[off].mm){
		++time;
		money += cost[tmp.hh];
		++tmp.mm;
		if(tmp.mm >= 60){
			tmp.mm = 0;
			++tmp.hh;
		}
		if(tmp.hh >= 24){
			tmp.hh = 0;
			++tmp.dd;
		}
	}
}

int main(){
	for(int i = 0; i < 24; ++i){
		scanf("%d", &cost[i]);
	}
	int N;
	int month;
	char on_off[20];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%s %d:%d:%d:%d %s", recs[i].name, &month, &recs[i].dd, &recs[i].hh, &recs[i].mm, on_off);
		if(on_off[1] == 'n'){
			recs[i].on_off = true;
		}else{
			recs[i].on_off = false;
		}
	}
	//for(int i = 0; i < N; ++i)
	//	printf("%s %d:%d:%d %s\n", recs[i].name, recs[i].dd, recs[i].hh, recs[i].mm, recs[i].on_off?"true":"false");
	sort(recs, recs+N, cmp);
	int on = 0, off, next;
	while(on < N){
		bool needPrint = false;
		next = on + 1;
		while(next < N && strcmp(recs[next].name, recs[on].name) == 0){
			if(recs[next-1].on_off == true && recs[next].on_off == false){
				needPrint = true;
			}
			++next;
		}
		if(needPrint == false){
			on = next;
			continue;
		}
		int all_money = 0;
		printf("%s %02d\n", recs[on].name, month);
		while(on < next){
			while(on < next - 1 && !(recs[on].on_off == true && recs[on+1].on_off == false)){
				++on;
			}
			off = on + 1;
			if(off == next){
				on = next;
				break;
			}
			printf("%02d:%02d:%02d ", recs[on].dd, recs[on].hh, recs[on].mm);
			printf("%02d:%02d:%02d ", recs[off].dd, recs[off].hh, recs[off].mm);
			int time = 0;
			int money = 0;
			get_time_money(on, off, time, money);
			all_money += money;
			printf("%d $%.2f\n", time, money / 100.0);
			on = off + 1;
		}
		printf("Total amount: $%.2f\n", all_money / 100.0);
	}
	return 0;
}