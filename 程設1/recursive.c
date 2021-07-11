#include<stdio.h>
#include<stdlib.h>
int R(int x1,int x2,int n){
    if(n==3){
        return x1+x2;
    }
    if(n<3){
        exit(0);
    }
    if(n>3){
        return R(x2,x1+x2,n-1);
    }
}
int main(){
    int x1,x2,n;
    while(scanf("%d%d%d",&x1,&x2,&n)!=EOF){
    printf("%d\n",R(x1,x2,n));}
    return 0;
}