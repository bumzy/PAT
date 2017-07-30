/*************************************************************************
	> File Name: B1063.cpp
	> Author: bumzy
	> Mail: bumzy@gmail.com
	> Created Time: 2017年07月30日 星期日 15时56分10秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
using namespace std;

const int MAXN = 10000 + 10;

int main(){
    double mo = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        double d1, d2;
        scanf("%lf%lf", &d1, &d2);
        if (mo < d1 * d1 + d2 * d2) {
            mo = d1 * d1 + d2 * d2;
        }
    }
    printf("%.2lf", sqrt(mo)); 
    return 0;
}
