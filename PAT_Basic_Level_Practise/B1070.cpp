/*************************************************************************
	> File Name: B1070.cpp
	> Author: bumzy
	> Mail: bumzycm@gmail.com
	> Created Time: Tue 01 Aug 2017 09:02:03 PM CST
 ************************************************************************/

#include <stdio.h>
#include <queue>
using namespace std;

int main() {                     
    priority_queue<double, std::vector<double>, std::greater<double> > Q;
    int n;                       
    scanf("%d", &n);             
    for (int i = 0; i < n; ++i) {
        double len;              
        scanf("%lf", &len);      
        Q.push(len);             
    }                            
    while (Q.size() > 1) {       
        double t1 = Q.top();     
        Q.pop();                 
        double t2 = Q.top();     
        Q.pop();                 
        Q.push((t1 + t2) / 2.0); 
    }                            
    printf("%d\n", (int) Q.top());                                                                                               
    return 0;                    
}
