#include<stdio.h>
char c;
int flag=0;
int main(){
    while((c=getchar())!='\n'){
        switch(c){
            case(' '):{
                if (flag==0){
                    printf("%c",c);
                    flag=1;
                }
                else{
                    break;
                }
                break;
            }
            default:{
                printf("%c",c);
                flag=0;
                break;
            }
        }
    }
    return 0;
}
