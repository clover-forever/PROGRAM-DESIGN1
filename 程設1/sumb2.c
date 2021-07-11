#include <stdio.h>
#include <string.h>

void add(char a[], char b[], char res[]);

int main()
{
    char a[100], b[100], res[105];
    scanf("%s %s", a, b);
    add(a, b, res);
    printf("%s", res);
    return 0;
}

// Your code goes here
void add(char a[], char b[], char res[])
{
    int numa = strlen(a);
    int numb = strlen(b);
    int A[100] = {0}, B[100] = {0};
    for (int i = numa - 1, j = 0; i >= 0; i--, j++)
    {
        A[j] = a[i] - '0';
    }
    for (int i = numb - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = b[i] - '0';
    }
    for (int i = 0; i < 100; i++)
    {
        A[i] += B[i];
        if (A[i] >= 10)
        {
            A[i] -= 10;
            A[i + 1]++;
        }
    }
    int i, k;
    for (i = 99; i >= 0 && A[i] == 0; i--)
        ;
   
        for (int j = i, k = 0; j >= 0; j--, k++)
        {
            res[k] = A[j] + '0';
            res[k+1]='\0';
        }
    
}
