#include <stdio.h>

int main(){
  int a,b;
  while(scanf("%d%d",&a,&b) == 2){
    int c=a+b;
    if(c<0){
      printf("-");
      c=0-c;
    }
    if(c>=1000000){
      printf("%d,%03d,%03d\n",c/1000000,(c%1000000)/1000,c%1000);
    }else if(c>=1000){
      printf("%d,%03d\n",c/1000,c%1000);
    }else{
      printf("%d\n",c);
    }
  }
}