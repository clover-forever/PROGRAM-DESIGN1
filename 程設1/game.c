#include<stdio.h>
int ha,hb,s,flag=1;
int main(){
    scanf("%d %d",&ha,&hb);
    while(scanf("%d",&s)!=EOF){
        if(flag==1){
            hb=hb-s;
            if(hb<1){
                printf("A");
                break;
            }
          flag=0;
          }
        else{
            ha=ha-s;
            if(ha<1){
              printf("B");
              break;
        }
          flag=1;
    }
    }
    return 0;
}
