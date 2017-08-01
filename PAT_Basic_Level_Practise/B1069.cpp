/*************************************************************************
	> File Name: B1069.cpp
	> Author: bumzy
	> Mail: bumzycm@gmail.com
	> Created Time: Tue 01 Aug 2017 08:18:25 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

static const int MAXM = 1000 + 10;
string name[MAXM];
unordered_map<string, int> M;
int main() {
    int m, n, s;
    cin >> m >> n >> s;
    for (int i = 0; i < m; ++i) {
        cin >> name[i];
        M[name[i]] = 0;
    }
    bool flag = false;
    for (int i = s - 1; i < m; i += n) {
        if (M[name[i]] == 0) {
            cout << name[i] << endl;
            M[name[i]] = 1;
            flag = true;
        } else {
            while (i < m && M[name[i]] == 1) {
                i++;
            }
            if (i < m) {
                cout << name[i] << endl;
                M[name[i]] = 1;
                flag = true;
            }
        }
    }
    if (flag == false) {
        cout << "Keep going..." << endl;
    }
    return 0;
}
