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
    struct node *p=malloc(sizeof(struct node));
    int max=0;
    for(p=head;p!=NULL;p=p->next){
        if(p->val>max){
            max=p->val;
        }
    }
    for(p=head;p->val!=max;p=p->next);//p=max
    if(p==tail){
        ;
    }
    else
    {
        if(p==head){
            tail->next=p;
            head=head->next;
            p->next=NULL;
        }
        if(p!=head){
            struct node *pre=malloc(sizeof(struct node));
            for(pre=head;pre->next->val!=max;pre=pre->next);
            pre->next=p->next;
            tail->next=p;
            p->next=NULL;
        }
    }
    
}
