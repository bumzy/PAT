#include <cstdio>
using namespace std;

int main() {
	int N, now = 0, next, time = 0;;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &next);
		if (next > now) time += (next - now) * 6;
		else if (next < now) time += (now - next) * 4;
		time += 5;
		now = next;
	}
	printf("%d\n", time);
	return 0;
}
