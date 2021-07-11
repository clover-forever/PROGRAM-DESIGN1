#include<stdio.h>
int a[1],b[6],c[5],d,sum;
int main(){
    scanf("%1d %1d%1d%1d%1d%1d%1d %1d%1d%1d%1d%1d",&a[0],&b[0],&b[1],&b[2],&b[3],&b[4],&b[5],&c[0],&c[1],&c[2],&c[3],&c[4]);
    sum=a[0]+b[1]+b[3]+b[5]+c[1]+c[3]+(b[0]+b[2]+b[4]+c[0]+c[2]+c[4])*3;
    sum=10-sum%10;
    if(sum==10)
      printf("0");
    else
      printf("%d",sum);
    return 0;
}