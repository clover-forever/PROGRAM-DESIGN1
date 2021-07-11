#include <stdio.h>
#include <stdlib.h>



int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
   int n,i;
scanf("%d",&n);
int A[n];
   
   for( i = 0 ; i < 5; i++ ) {
      scanf("%d",&A[i]);
   }

   qsort(A, n, sizeof(int), cmpfunc);

   printf("After sorting the list is: ");
   for( i = 0 ; i < n; i++ ) {
      printf("%d ", A[i]);
   }
  
  return(0);
}