#include<stdio.h>
char c;
int main(){
    while((c=getchar())!=EOF){
        switch(c){
            case('A'):{
                printf("C");
                break;
            }
            case('B'):{
                printf("R");
                break;
            }
            case('C'):{
                printf("W");
                break;
            }
            case('D'):{
                printf("Z");
                break;
            }
            case('E'):{
                printf("G");
                break;
            }
        }
    }
    return 0;
}
