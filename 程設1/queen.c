#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char value[3];
    struct Node* next;
}Node;

int main(){
    char draw_order[13][3] = {"K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A"};
    int next_draw = 0;
    Node *front, *p;
    char line[3];

    if(scanf("%s", line) != EOF){
        p = malloc(sizeof(Node));
        p->next = NULL;
        strcpy(p->value, line);
        front = p;
    }

    while(scanf("%s", line) != EOF){
        Node* new_card = malloc(sizeof(Node));
        new_card->next = NULL;
        strcpy(new_card->value, line);
        p = p->next = new_card;
    }

    while(next_draw < 13){
        p = front;
        while(p != NULL){
            printf("%s ", p->value);
            p = p->next;
        }
        printf("\n");

        if(strcmp(front->value, draw_order[next_draw])){
            p = front;
            while(p != NULL){
                if(p->next == NULL)
                    break;
                p = p->next;
            }
            p->next = front;
            front = front->next;
            p->next->next = NULL;
        }else{
            Node* to_release = front;
            front = front->next;
            free(to_release);
            next_draw++;
        }
    }

    return 0;
}
