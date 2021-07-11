#include<stdio.h>
long combination;
int m,n,i=1,j=1;
unsigned long long fact=1,fact1=1;

int main(){ 
    scanf("%d %d",&m,&n);
    if (n>(m/2)){
        
    for(i=n+1;i<=m;i++)
      fact1*=i;
    for(j=1;j<=m-n;j++)
      fact*=j;
    printf("%llu",fact1/fact);}
    else{
    n=m-n;
    for(i=n+1;i<=m;i++)
      fact1*=i;
    for(j=1;j<=m-n;j++)
      fact*=j;
    printf("%llu",fact1/fact);
    }
    return 0;
}
