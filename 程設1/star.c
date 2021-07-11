#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x , y , i , n;
    scanf("%d",&n);

    for(x=1 ; x<=n*2-1 ; x++)
    {
       if (x % 2 !=0)               //x = 1,3,5,7(the number of star)
       {
          for(i=0 ; i<((n*2-1)-x)/2 ; i++)   
             printf(" ");
          for(y=1 ; y<=x ; y++)                   
             printf("*");
       }
       else
          printf("\n");
    }
    printf("\n");
    return 0;
}
