#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

int addition(char str[]);

int main()
{
    char str[N];
    scanf("%s", str);
    int sum = addition(str);
    printf("%d", sum);
    return 0;
}
int addition(char str[])
{
    char *token;
    char s[2] = "+";
    int sum=0;
    /* get the first token */
    token = strtok(str, s);
    /* walk through other tokens */
    while (token != NULL)
    {
        int val=atoi(token);
        sum+=val;
        token = strtok(NULL, s);
        printf("%s",token);
    }
    return sum;
}