#include <stdio.h>

void star(int*, int*);

int main()
{
    int arr[5], result;
    for(int i=0; i<5; i++)
        scanf("%d", &arr[i]);
    
    star(arr, &result);

    printf("%d", result);

    return 0;
}
void star(int* arr, int* result) {
    int *p,sum=0;
    
    for (p=&arr[0]; p < &arr[5]; p++){
         sum+=*p;
    }
    *result=sum;
}