#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int k;
	int n;
	double a;
	while(cin>>k){
		map<int, double> m1;
		map<int, double> m2;
		map<int, double> m;
		for(int i = 0; i < k; ++i){
			cin>>n>>a;
			m1[n] = a;
		}
		cin>>k;
		for(int i = 0; i < k; ++i){
			cin>>n>>a;
			m2[n] = a;
		}
		int minmum = min(m1.begin()->first, m2.begin()->first);
		int maximum = max(m1.rbegin()->first, m2.rbegin()->first);
		for(int i = minmum; i <= maximum; ++i)
		{
			if(m1.find(i) != m1.end() && m2.find(i) != m2.end())
			{
				if(m1[i] + m2[i] != 0)
					m[i] = m1[i] + m2[i];
			}else if(m1.find(i) != m1.end() && m1[i] != 0)
			{
				m[i] = m1[i];
			}else if(m2.find(i) != m2.end() && m2[i] != 0)
			{
				m[i] = m2[i];
			}
		}
		printf("%d", (int)m.size());
		for(auto it = m.rbegin(); it != m.rend(); ++it)
		{
			//cout<<" "<<it->first<<" "<<it->second;
			printf(" %d %.1lf", it->first, it->second);
		}
		//cout<<endl;
	}
	return 0;
}