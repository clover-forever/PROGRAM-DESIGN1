#include <stdio.h>

int GCD(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return GCD(b, a % b);
    }
}

int main()
{
    printf("Input two numbers: ");
    int a, b;
    scanf(" %d %d", &a, &b);

    int result = GCD(a, b);
    printf("GCD result: %d\n", result);
}