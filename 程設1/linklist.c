#include<stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node*next;
};
int main(){
    struct node*head,*p;
    head->data=1;
    head->next=NULL;
    p=head;
    printf("%d",head->data);
    for(int i=1;i<7;i++){
        struct node*t = malloc(sizeof(struct node));
        p->next=t;
        //t->next=NULL;
        t->data=i+1;
        p=p->next;
        printf("%d",t->data);
    }

    return 0;
}