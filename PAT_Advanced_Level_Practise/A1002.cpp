#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	double a[1001], b[1001];
	for(int i = 0; i < 1001; ++i) a[i]=b[i]=0;
	int n,k;
	double v;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> k >> v;
		a[k] = v;
	}
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> k >> v;
		b[k] = v;
	}
	int ans = 0;
	for(int i = 0; i <= 1000; ++i){
		a[i] += b[i];
		if(a[i]) ++ans;
	}
	printf("%d", ans);
	for(int i = 1000; i>= 0; --i){
		if(a[i]) printf(" %d %.1lf", i, a[i]);
	}
	return 0;
}