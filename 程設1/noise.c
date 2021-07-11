#include<stdio.h>
int A[10],i,j,a,max=100;
long B[100];
int main(){
    for(i=0;i<10;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            a=((i+1)-(j+1))*(A[i]+A[j]);
            if(a<0){
                a=-a;
            }
            if(a>max){
                max=a;
            }
            
        }
        
    }
    printf("%d",max);
    return 0;
}