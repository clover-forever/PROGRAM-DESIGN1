#include<stdio.h>
long int B(int i){
    if (i<=2){
        return 1;
    }
    else{
        return (2*B(i-1)+3*B(i-2))%1000000007;
    }
}
int main(){
    int i;
    scanf("%d",&i);
    printf("%ld",B(i));
    return 0;
}