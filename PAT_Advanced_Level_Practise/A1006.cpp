#include <cstdio>
#include <cstring>
using namespace std;

struct Time {
	int hour;
	int munite;
	int second;
	Time() : hour(0), munite(0), second(0) {}
	Time(int h, int m, int s) : hour(h), munite(m), second(s) {}
	bool operator < (const Time &t) const {
		if (hour != t.hour) return hour < t.hour;
		else if (munite != t.munite) return munite < t.munite;
		else return second < t.second;
	}
	bool operator > (const Time &t) const {
		return t < *this;
	}
	Time &operator = (const Time &t) {
		hour = t.hour;
		munite = t.munite;
		second = t.second;
		return *this;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	char id[16], first_id[16], last_id[16];
	Time in, out, first(23, 59, 59), last;
	while (n--) {
		scanf("%s %d:%d:%d %d:%d:%d", id, &in.hour, &in.munite, &in.second, &out.hour, &out.munite, &out.second);
		if (in < first) {
			first = in;
			strcpy(first_id, id);
		}
		if (out > last) {
			last = out;
			strcpy(last_id, id);
		}
	}
	printf("%s %s", first_id, last_id);
	return 0;
}