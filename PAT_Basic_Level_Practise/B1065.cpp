/*************************************************************************
	> File Name: B1065.cpp
	> Author: bumzy
	> Mail: bumzy@gmail.com
	> Created Time: 2017年07月30日 星期日 16时38分28秒
 ************************************************************************/

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    unordered_map<int, int> couple;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    scanf("%d", &m);
    unordered_set<int> guest;
    vector<int> single;
    for (int i = 0; i < m; ++i) {
        int id;
        scanf("%d", &id);
        guest.insert(id);
    }
    for(auto i = guest.begin(); i != guest.end(); ++i) {
        if (couple.find(*i) == couple.end() || 
           (guest.find(couple[*i]) == guest.end())) {
            single.push_back(*i);
        }
    }
    sort(single.begin(), single.end());
    printf("%lu\n", single.size());
    for (size_t i = 0; i < single.size(); ++i) {
        printf("%05d", single[i]);
        if (i < single.size() - 1) {
            printf(" ");
        }
    }
    return 0;
}
