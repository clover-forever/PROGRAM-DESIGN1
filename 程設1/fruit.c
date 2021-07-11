#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20000

void find_fruit(char input[], char fruit[][15]);

int main(void)
{
    char fruit[20][15] = {
        "guava",
        "litchi",
        "longan",
        "watermelon",
        "pomelo",
        "pear",
        "banana",
        "papaya",
        "pumpkin",
        "tomato",
        "mango",
        "kiwi",
        "persimmon",
        "cantaloupe",
        "strawberry",
        "grape",
        "peach",
        "orange",
        "coconut",
        "lemon"};
    char input[N];
    scanf("%s", input);
    find_fruit(input, fruit);
    return 0;
}
void find_fruit(char input[], char fruit[][15])
{
    // input is the fruit sequence eg: watermelon+_+watermelon+_+coconut+_+grape+_+coconut
    // fruit is 20 kinds of fruit name eg: fruit[0] is "guava", fruit[1] is litchi and so on.
    // you need to check the Loader code to understand above meaning
    char *token;
    char s[4] = "+_+";
    int check[20]={0};
    /* get the first token */
    token = strtok(input, s);
    /* walk through other tokens */

    while (token != NULL)
    {
        for(int i=0;i<20;i++){
          if(strcmp(token,fruit[i])==0){
              check[i]++;
              
          }  
        }
        token = strtok(NULL, s);   
    }
    int max=0;
    for(int i=0;i<20;i++){
        if(check[i]>=max){
            max=check[i];
        }
    }
    for(int i=0;i<20;i++){
        if(check[i]==max){
            printf("%s\n",fruit[i]);
        }
    }
    
}