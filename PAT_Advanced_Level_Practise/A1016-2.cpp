#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;
int N, cost[24];
struct Recond {
	string name;
	int mon, d, h, m;
	bool on;
} recond[MAXN];

bool cmp(const Recond& r1, const Recond& r2) {
	if (r1.name != r2.name) return r1.name < r2.name;
	else if (r1.d != r2.d) return r1.d < r2.d;
	else if (r1.h != r2.h) return r1.h < r2.h;
	else return r1.m < r2.m;
}

int main() {
	for (int i = 0; i < 24; ++i) {
		scanf("%d", &cost[i]);
	}
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		char name[24], status[24];
		scanf("%s %d:%d:%d:%d %s", name, &recond[i].mon,
		      &recond[i].d, &recond[i].h, &recond[i].m, status);
		recond[i].name = string(name);
		recond[i].on = status[1] == 'n' ? true : false;
	}
	sort(recond, recond + N, cmp);
	/*for(int i = 0; i < N; ++i){
		printf("%s %02d:%02d:%02d %d\n", recond[i].name.c_str(), recond[i].d, recond[i].h, recond[i].m, recond[i].on);
	}*/
	int i = 0;
	while (i + 1 < N) {
		string name = recond[i].name;
		bool first = true;
		int total = 0;
		while (i + 1 < N && name == recond[i].name && name == recond[i + 1].name) {
			if (!(recond[i].on == true && recond[i + 1].on == false)) {
				i++;
				continue;
			}
			if (first) {
				printf("%s %02d\n", name.c_str(), recond[i].mon);;
				first = false;
			}
			int line = 0, munite = 0;
			int d = recond[i].d, h = recond[i].h, m = recond[i].m;
			int d2 = recond[i + 1].d, h2 = recond[i + 1].h, m2 = recond[i + 1].m;
			printf("%02d:%02d:%02d %02d:%02d:%02d ", d, h, m, d2, h2, m2);
			while (d < d2) {
				munite += (60 - m);
				line += cost[h] * (60 - m);
				m = 0;
				h++;
				while (h < 24) {
					munite += 60;
					line += cost[h] * 60;
					h++;
				}
				h = 0;
				d++;
			}
			while (h < h2) {
				munite += (60 - m);
				line += cost[h] * (60 - m);
				m = 0;
				h++;
			}
			munite += (m2 - m);
			line += cost[h] * (m2 - m);
			printf("%d $%.2lf\n", munite, line / 100.0);
			total += line;
			i += 2;
		}
		if (!first)
			printf("Total amount: $%.2lf\n", total / 100.0);
		if (name == recond[i].name)
			i++;
	}
	return 0;
}