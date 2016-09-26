#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Persion{
	char id[12];
	int virtue, talent, total, level;
	bool operator < (const Persion &p) const{
		if(level != p.level) return level > p.level;
		else if(total != p.total) return total > p.total;
		else if(virtue != p.virtue) return virtue > p.virtue;
		else return strcmp(id, p.id) < 0;
	}
} men[100010];

int main(){
	int N, L, H;
	int cnt = 0;
	scanf("%d%d%d", &N, &L, &H);
	for(int i = 0; i < N; ++i){
		char id[12];
		int v, t;
		scanf("%s%d%d", id, &v, &t);
		if(v >= L && t >= L){
			strcpy(men[cnt].id, id);
			men[cnt].virtue = v;
			men[cnt].talent = t;
			men[cnt].total = v + t;
			if(v >= H && t >= H){
				men[cnt].level = 4;
			}else if(v >= H && t < H){
				men[cnt].level = 3;
			}else if(v >= t){
				men[cnt].level = 2;
			}else{
				men[cnt].level = 1;
			}
			++cnt;
		}
	}
	printf("%d\n", cnt);
	sort(men, men+cnt);
	for(int i = 0; i < cnt; ++i){
		printf("%s %d %d\n", men[i].id, men[i].virtue, men[i].talent);
	}
	return 0;
}