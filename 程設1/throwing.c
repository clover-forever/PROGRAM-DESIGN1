#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    struct node *head = malloc(sizeof(struct node));
    struct node *p = malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;
    p = head;
    for (int i = 1; i < m; i++)
    {
        struct node *t = malloc(sizeof(struct node));
        p->next = t;
        t->next = NULL;
        t->data = i + 1;
        p = p->next;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", head->data); //頭
        p = head;
        while (p->next != NULL)
            p = p->next;
        head = head->next;
        p->next = head;
        if (head != NULL)//if head=NULL,then can't head=head->next
        {
            head = head->next;
            p->next->next = NULL;
        }
    }
}