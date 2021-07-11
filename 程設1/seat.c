#include <stdio.h>
int n,x,a,b;
int main(){
    scanf("%d %d %d",&n,&x,&a);
    b=x+a;
    while(b>=n)
      b=b%n;
printf("%d",b);
      return 0;
}