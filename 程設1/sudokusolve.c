#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

int sudo[9][9];

bool checkplace(int count){
    //0~80的座標
    int row = count / 9;
    int col = count % 9;

    //for row
    for(int i = 0;i<9;i++){
        if(sudo[row][col]==sudo[row][i] && col!=i)
            return false;
    }
    //for col
    for(int i = 0;i<9;i++){
        if(sudo[row][col]==sudo[i][col] && row!=i)
            return false;
    }
    //for cell
    int cellRow = row / 3 * 3;
    int cellCol = col / 3 * 3;

    for(int i = cellRow;i < cellRow + 3;i++){
        for(int j = cellCol;j < cellCol + 3;j++){
            if(sudo[row][col]==sudo[i][j] && row!=i && col!=j)
                return false;
        }
    }
    return true;
}

//重點
void backtrace(int count){
    //填完all數獨
    if(count == 81){
        printf("有一解\n");
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                printf("%d ",sudo[i][j]);
            }
            printf("\n");
        }
    }

    //開始backtrace
    int row=count/9;
    int col=count%9;
    if(sudo[row][col]==0) {
        for(int i=1; i<=9; ++i) {
            sudo[row][col]=i;
            if(checkplace(count)) {
                backtrace(count+1);
            }
        }
        sudo[row][col]=0;
    } else {
        backtrace(count+1);
    }
}

int main(){
    int i=0,j=0;
    int num;
    int zeronum = 0;

    for(i = 0;i<9;i++){
        for(j = 0;j<9;j++){
            scanf("%d",&num);
            sudo[i][j] = num;
            if(num == 0)zeronum++;
        }
    }

    if(zeronum>=65) {
        printf("have many solution");
        exit(0);
    }
    //如何判斷很多解呢？
    else if(zeronum==23) {
        printf("have no solution");
        exit(0);
    } else {
        backtrace(0);
    }
}