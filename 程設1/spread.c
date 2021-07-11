#include <stdio.h>
#define M 5
#define N 8
char colors[4] = {'R', 'G', 'B', 'X'};   // Red, Green, Blue, Empty

void spread(char*, int, int);

int main(void) {
    char graph[M][N];
    int row, col;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            scanf("%c", &graph[i][j]);
        getchar();      // Ignore '\n'
    }
    scanf("%d %d", &row, &col);    // Starting position
    
    spread(&graph[0][0], row, col);
    
    // Print out the spreading result
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}
void spread(char* graph, int row, int col) {
   char color= *(graph+row*N+col);

   for (int i=row-1;i>-1;i--){
    //    printf("%d\n",row);
    //    printf("%d %d %d\n",row,col,row*i+col);
       if(*(graph+N*i+col)=='X'||*(graph+N*i+col)==color){
           *(graph+N*i+col)=color;
           //printf("%d",row*i+col);
       }
       
       else
       {
          break; 
       }
       
   }
   for (int i=row+1;i<7;i++){
    //    printf("%d\n",row);
    //    printf("%d %d %d\n",row,col,row*i+col);
       if(*(graph+N*i+col)=='X'||*(graph+N*i+col)==color){
           *(graph+N*i+col)=color;
           //printf("%d",row*i+col);
       }
       
       else
       {
          break; 
       }
       
   }
    for (int i=col-1;i>-1;i--){
    
       if(*(graph+N*row+i)=='X'||*(graph+N*row+i)==color){
           *(graph+N*row+i)=color;
          
       }
       
       else
       {
          break; 
       }
       
   }   
    for (int i=col+1;i<8;i++){
    
       if(*(graph+N*row+i)=='X'||*(graph+N*row+i)==color){
           *(graph+N*row+i)=color;
          
       }
       
       else
       {
          break; 
       }
       
   } 
}