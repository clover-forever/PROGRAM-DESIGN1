#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
void MoveToTail();

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        struct node *tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if (i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for (struct node *cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->val);
    return 0;
}
// Your code goes here
void MoveToTail()
{
    struct node* p = malloc(sizeof(struct node));
    p = head;
    int max = 0;
    for(;p!=NULL;p = p->next){
        if(p->val>max)max = p->val;
    }
    
    p = head;
    for(;p->val!=max;p = p->next);
    
    struct node* prep = malloc(sizeof(struct node));
    prep = head;
    if(head->val!=max)
        for(;prep->next->val!=max;prep = prep->next);
    
    if(head->val!=max&&tail->val!=max){
        prep->next = p->next;
        p->next = head;
        head = p;
    }
    if(head->val!=max&&tail->val==max){
        prep->next =NULL;
        tail->next = head;
        head = tail;
    }
   
}
