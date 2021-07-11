#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
void MoveToTail();

int main(void) { 
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node* tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node* cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->val); 
    return 0;
}
// Your code goes here
void MoveToTail() {
    // "struct node* head" and "struct node* tail" are in global
    // you can use this two pointers to do this problem
    int min=5;
    struct node *p=malloc(sizeof(struct node));
    for(p=head;p!=NULL;p=p->next){
        if(p->val<min){
            min=p->val;
        }
    }
    for(p=head;p->val!=min;p=p->next){
        ;
    }//p=min
    if(p==head){
        ;
    }
    else
    {
        struct node *pre=malloc(sizeof(struct node));
        for(pre=head;pre->next->val!=min;pre=pre->next);
        if(p==tail){
            pre->next=NULL;
            p->next=head;
            head=p;
        }
        else
        {
            pre->next=p->next;
            p->next=head;
            head=p;
        }
    }
}