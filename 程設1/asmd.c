#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char a[501];
char b[501];
char c[1001];
int a_len, b_len;
char operator;

void swapstr(char **str1_ptr, char **str2_ptr)
{
    char *temp = *str1_ptr;
    *str1_ptr = *str2_ptr;
    *str2_ptr = temp;
}

void sum()
{
    if (a_len < b_len)
    {
        swapstr(a, b);
        int t = a_len;
        a_len = b_len;
        b_len = t;
    }

    int carry = 0;
    int sum = 0;

    int i = a_len - 1, j = b_len - 1;
    for (; j >= 0; i--, j--)
    {
        sum = (a[i] - '0' + b[i] - '0' + carry);
        carry = sum / 10;
        sum %= 10;
        c[i] = sum + '0';
    }

    for (; i >= 0; i--)
    {
        sum = a[i] - '0' + carry;
        carry = sum / 10;
        sum %= 10;
        c[i] = sum + '0';
    }
}

bool cmp()
{
    if (a_len != b_len)
        return a_len > b_len;
    for (int i = 0; i < a_len; i++)
    {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
}
void sub()
{
    int borrow[501];
    bool negative;
    int i, j;

    if (cmp())
        negative = false;
    else
    {
        negative = true;
        swapstr(a, b);
        int t = a_len;
        a_len = b_len;
        b_len = t;
    }
    borrow[0] = a[0] - '0';
    for (i = 1; i < a_len; i++)
    {
        borrow[i - 1]--;
        borrow[i] = (a[i] - '0') + 10;
    }
    for (i = a_len - 1, j = b_len - 1; j >= 0; i--, j--)
    {
        borrow[i] -= (b[j] - '0');
    }
    for (i = a_len - 1; i >= 0; i--)
    {
        borrow[i - 1] += borrow[i] / 10;
        borrow[i] %= 10;
    }
    if (negative)
    {
        c[0] = '-';
        for (i = a_len - 1; i >= 0; i--)
            c[i + 1] = borrow[i] + '0';
    }
    else
    {
        for (i = a_len - 1; i >= 0; i--)
            c[i] = borrow[i] + '0';
    }
}

void mul()
{
    int sum[1001] = {0};
    int i, j;
    for (i = a_len - 1; i >= 0; i--)
    {
        for (j = b_len - 1; j >= 0; j--)
        {
            sum[i + j + 1] += ((a[i] - '0') * (b[j] - '0'));
        }
    }
    for (int k = a_len + b_len - 1; k >= 1; k--)
    {
        sum[k - 1] += sum[k] / 10;
        sum[k] %= 10;
    }

    for (int k = a_len + b_len - 1; k >= 0; k--)
    {
        c[k] = sum[k] + '0';
    }
}

void div()
{
    int remainder[501] = {0};
    int quotient[501] = {0};
    for (int i = 0; i < a_len; i++)
    {
        remainder[i] = a[i] - '0';
    }

    for (int k = 0; k < (a_len - b_len + 1); k++)
    {
        while (remainder[k] >= 0)
        {
            for (int j = 0; j < b_len; j++)
            {
                remainder[k + j] -= (b[j] - '0');
                if ((remainder[k + j] < 0) && (j > 0))
                {
                    remainder[k + j - 1]--;
                    remainder[k + j] += 10;
                }
            }
            quotient[k]++;
        }
        for (int j = 0; j < b_len; j++)
        {
            remainder[k + j] += b[j] - '0';
        }
        quotient[k]--;
        remainder[k + 1] += remainder[k] * 10;
        remainder[k] = 0;

        c[k] = (quotient[k] + '0');
    }
}

int main()
{
    while (scanf("%s %c %s", a, &operator, b) != EOF)
    {
        a_len = strlen(a);
        b_len = strlen(b);

        switch (operator)
        {
        case '+':
            sum();
            break;
        case '-':
            sub();
            break;
        case '*':
            mul();
            break;
        case '/':
            div();
            break;
        }

        if (c[0] != '0')
            printf("%c", c[0]);
        if (strlen(c))
        {
            for (int i = 1; i < strlen(c); i++)
                printf("%c", c[i]);
                printf("\n");
        }
        else
            printf("0");
    }
    return 0;
}
