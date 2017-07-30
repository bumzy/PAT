/*************************************************************************
	> File Name: B1064.cpp
	> Author: bumzy
	> Mail: bumzy@gmail.com
	> Created Time: 2017年07月30日 星期日 16时10分03秒
 ************************************************************************/

#include <stdio.h>
using namespace std;
int const MAX = 64;

int sum_of_digit(int num) {
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int count[MAX] = {0};

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        count[sum_of_digit(num)]++;
    }
    int m = 0;
    for (int i = 0; i < MAX; ++i) {
        if (count[i]) {
            m++;
        }
    }
    printf("%d\n", m);
    bool first = true;
    for (int i = 0; i < MAX; ++i) {
        if (count[i]) {
            if (first) {
                first = false;
            } else {
                printf(" ");
            }
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}
