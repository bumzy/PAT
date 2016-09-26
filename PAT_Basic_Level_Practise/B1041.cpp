#include <cstdio>

const int MAXN = 1000 + 10;
struct student{
	long long id;
	int examSeat;
	student():id(0), examSeat(0){}
	student(long long i, int e) : id(i), examSeat(e){}
}testSeat[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		long long id;
		int t, e;
		scanf("%lld%d%d", &id, &t, &e);
		testSeat[t] = student(id, e);
	}
	scanf("%d", &n);
	while(n--){
		int t;
		scanf("%d", &t);
		printf("%lld %d\n", testSeat[t].id, testSeat[t].examSeat);
	}
	return 0;
}