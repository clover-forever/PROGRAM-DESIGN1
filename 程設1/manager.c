#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *good_types[] = {
    "Juice",
    "Wine",
    "Laptop"};

void *produce(void *top_of_stack, const char *good_type, size_t count);
void *consume(void *top_of_stack, size_t count);
void list_remain(void *top_of_stack);

int main()
{
    char record[64], *job, *good;
    size_t count;
    void *top_of_stack = NULL;

    while (fgets(record, 64, stdin))
    {
        job = strtok(record, " ");
        if (!strcmp(job, "Produce"))
        {
            good = strtok(NULL, " ");
            count = atol(strtok(NULL, " "));

            for (int i = 0; i < 3; i++)
            {
                if (!strcmp(good, good_types[i]))
                {
                    top_of_stack = produce(top_of_stack, good_types[i], count);
                    break;
                }
            }
        }
        else if (!strcmp(job, "Consume"))
        {
            count = atol(strtok(NULL, " "));
            top_of_stack = consume(top_of_stack, count);
        }
    }

    list_remain(top_of_stack);

    return 0;
}
// Your code goes here
int top = 0, stk[2500000];

int get_type(const char *good_type)
{
    for (int i = 0; i < 3; i++)
        if (!strcmp(good_type, good_types[i]))
            return i;
    return 87;
}

void *produce(void *top_of_stack, const char *good_type, const size_t count)
{
    int type = get_type(good_type), cnt = count;

    while (cnt--)
        stk[top++] = type;
}

void *consume(void *top_of_stack, const size_t count)
{
    top -= count;
}

void list_remain(void *top_of_stack)
{
    int cnt = 0, tmp = stk[top - 1];

    if (top)
    {
        for (int i = top - 1; i >= 0; i--)
        {
            if (!i || tmp != stk[i - 1])
            {
                printf("%s x %d\n", good_types[tmp], cnt + 1);

                cnt = 0, tmp = stk[i - 1];
            }
            else
                cnt++;
        }
    }
    else
        puts("Empty");
}
