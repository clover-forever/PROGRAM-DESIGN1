#include<stdio.h>
int n,i,j,flag=0;
int main(){
    scanf("%d",&n);
    int A[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(A[i][j]!=A[j][i]){
                flag=1;
                break;
            }
        }
    }
    if(flag==1)
        printf("No\n");
    else if(flag==0){
        printf("Yes\n");
    }
    return 0;
}
