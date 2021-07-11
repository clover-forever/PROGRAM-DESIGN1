#include<stdio.h>
int A[32],B[32],C[32];
int pre=0,i;
int main(){
  for(i=0;i<32;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<32;i++){
    scanf("%d",&B[i]);
  }
  for(i=31;i>=0;i--){
      C[i]=A[i]+B[i]+pre;
      if(C[i]>1){
        C[i]=C[i]%2;
        pre=1;
      }
      else{
        pre=0;
      }
  }
  for(i=0;i<32;i++){
    printf("%d ",C[i]);
  }
    return 0;
}


