#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 10;
const int MAXK = 110;
const int INF = 0x3fffffff;

int N, K;
struct Customer {
	int comeTime, serveTime;
} newCustomer;
vector<Customer> customer;
int endTime[MAXK];

bool cmp(const Customer &c1, const Customer &c2){
	return c1.comeTime < c2.comeTime;
}

int convertTime(int h, int m, int s){
	return h * 3600 + m * 60 + s;
}

int main(){
	scanf("%d%d", &N, &K);
	int stTime = convertTime(8, 0, 0);
	int edTime = convertTime(17, 0, 0);
	for(int i = 0; i < K; ++i){
		endTime[i] = stTime;
	}
	for(int i = 0; i < N; ++i){
		int h, m, s, serveTime;
		scanf("%d:%d:%d %d", &h, &m, &s, &serveTime);
		int comeTime = convertTime(h, m, s);
		if(comeTime > edTime) continue;
		newCustomer.comeTime = comeTime;
		newCustomer.serveTime = serveTime <= 60 ? serveTime*60 : 3600;
		customer.push_back(newCustomer);
	}
	sort(customer.begin(), customer.end(), cmp);
	int totTime = 0;
	for(int i = 0; i < customer.size(); ++i){
		int idx = -1, minEndTime = INF;
		for(int j = 0; j < K; ++j){
			if(endTime[j] < minEndTime){
				idx = j;
				minEndTime = endTime[j];
			}
		}
		if(endTime[idx] <= customer[i].comeTime){
			endTime[idx] = customer[i].comeTime + customer[i].serveTime;
		}else{
			totTime += (endTime[idx] - customer[i].comeTime);
			endTime[idx] += customer[i].serveTime;
		}
	}
	if(customer.size() == 0) printf("0.0");
	else printf("%.1lf", totTime / 60.0 / customer.size());
	return 0;
}