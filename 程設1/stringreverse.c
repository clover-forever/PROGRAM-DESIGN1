#include<stdio.h>
int n,i;
int main(){
    scanf("%d\n",&n);
    char A[n];
    for(i=0;i<n;i++){
        scanf("%c",&A[i]);
    }
    for(i=n-1;i>=0;i--){
        printf("%c",A[i]);
    }
    return 0;
}
