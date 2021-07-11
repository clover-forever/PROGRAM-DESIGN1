#include<stdio.h>
#include<string.h>

char* reference(char author[], char title[], char conference[], char location[], char date[], char ppdoi[]);

int main(){
    char author[100], title[150], conference[150], location[30], date[5], ppdoi[60];
    scanf("%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]", author, title, conference, location, date, ppdoi);
    printf("%s", reference(author, title, conference, location, date, ppdoi));
    return 0;
}
char* reference(char author[], char title[], char conference[], char location[], char date[], char ppdoi[]){
    static char result[300];
    // Your code goes here
    strcat(author,", \"");
    strcat(author,title);
    strcat(author,",\" ");
    strcat(author,conference);
    strcat(author,", ");
    strcat(author,location);
    strcat(author,", ");
    strcat(author,date);
    strcat(author,", ");
    strcat(author,ppdoi);
    strcat(author,".");
    strcpy(result,author);
    return result;
}