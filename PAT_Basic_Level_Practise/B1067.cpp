/*************************************************************************
	> File Name: B1067.cpp
	> Author: bumzy
	> Mail: bumzy@gmail.com
	> Created Time: 2017年07月30日 星期日 17时48分06秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string pw, input;
    int n, cnt = 0;
    cin >> pw >> n;
    getchar();
    while (getline(cin, input) && input != "#") {
        cnt++;
        if (cnt <= n && input == pw) {
            cout << "Welcome in" << endl;
            break;
        } else {
            cout << "Wrong password: " << input << endl;
        }
        if (cnt == n) {
            cout << "Account locked" << endl;
            break;
        }
    }
    return 0;
}
