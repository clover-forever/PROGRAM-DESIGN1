#include<stdio.h>
int i,j,a,b,flag;
int main(){
    scanf("%d%d",&a,&b);
    for(i=a;i<=b;i++){
        flag=0;
        for(j=2;j<i;j++){
            if(i%j==0){
                flag=1;
                break;
            }
            else{
                flag=0;
            }
        }
        if(flag==0&&i!=1){
            printf("%d ",i);
        }
    }
    return 0;
}
