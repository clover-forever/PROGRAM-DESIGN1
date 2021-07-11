#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
/* external variables */
int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
int card_exit[13][4];
bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */
void read_cards(void);
void analyze_hand();
void quicksort(int a[], int low, int high);
int print_result(void);
int split(int a[], int low, int high);
int main(void)
{
    int E[4];
    for (int i = 0; i < 4; i++)
    {
        read_cards();
        int rank,suit;
        analyze_hand(rank,suit);
        E[i] = print_result();
    }
    int A = E[0];
    int B = E[1];
    int C = E[2];
    int D = E[3];
    
    if (A>=B&&B>=C&&C>=D){
        printf("A B C D ");
    }
    else if(A>=B&&B>=D&&D>=C){
        printf("A B D C ");
    }
    else if(A>=C&&C>=B&&B>=D){
        printf("A C B D ");
    }
    else if(A>=C&&C>=D&&D>=B){
        printf("A C D B ");
    }
    else if(A>=D&&D>=B&&B>=C){
        printf("A D B C ");
    }
    else if(A>=D&&D>=C&&C>=B){
        printf("A D C B ");
    }
    else if(B>=A&&A>=C&&C>=D){
        printf("B A C D ");
    }
    else if(B>=A&&A>=D&&D>=C){
        printf("B A D C ");
    }
    else if(B>=C&&C>=A&&A>=D){
        printf("B C A D ");
    }
    else if(B>=C&&C>=D&&D>=A){
        printf("B C D A ");
    }
    else if(B>=D&&D>=A&&A>=C){
        printf("B D A C ");
    }
    else if(B>=D&&D>=C&&C>=A){
        printf("B D C A ");
    }
    else if(C>=A&&A>=B&&B>=D){
        printf("C A B D ");
    }
    else if(C>=A&&A>=D&&D>=B){
        printf("C A D B ");
    }
    else if(C>=B&&B>=A&&A>=D){
        printf("C B A D ");
    }
    else if(C>=B&&B>=D&&D>=A){
        printf("C B D A ");
    }
    else if(C>=D&&D>=A&&A>=B){
        printf("C D A B ");
    }
    else if(C>=D&&D>=B&&B>=A){
        printf("C D B A ");
    }
    else if(D>=A&&A>=B&&B>=C){
        printf("D A B C ");
    }
    else if(D>=A&&A>=C&&C>=B){
        printf("D A C B ");
    }
    else if(D>=B&&B>=A&&A>=C){
        printf("D B A C ");
    }
    else if(D>=B&&B>=C&&C>=A){
        printf("D B C A ");
    }
    else if(D>=C&&C>=A&&A>=B){
        printf("D C A B ");
    }
    else if(D>=C&&C>=B&&B>=A){
        printf("D C B A ");
    }}
void read_cards(void)
{
    char ch, rank_ch, suit_ch;
    int rank, suit;
    int card[NUM_RANKS][NUM_SUITS];
    bool bad_card;
    int cards_read = 0;
    /* initialize */
    for (rank = 0; rank < NUM_RANKS; rank++)
    {
        num_in_rank[rank] = 0;
    }
    for (suit = 0; suit < NUM_SUITS; suit++)
        num_in_suit[suit] = 0;

    while (cards_read < NUM_CARDS)
    {
        rank_ch = getchar();
        switch (rank_ch)
        {
        case '0':
            exit(EXIT_SUCCESS);
        case '2':
            rank = 0;
            break;
        case '3':
            rank = 1;
            break;
        case '4':
            rank = 2;
            break;
        case '5':
            rank = 3;
            break;
        case '6':
            rank = 4;
            break;
        case '7':
            rank = 5;
            break;
        case '8':
            rank = 6;
            break;
        case '9':
            rank = 7;
            break;
        case 't':
            rank = 8;
            break;
        case 'j':
            rank = 9;
            break;
        case 'q':
            rank = 10;
            break;
        case 'k':
            rank = 11;
            break;
        case 'a':
            rank = 12;
            break;
        }
        suit_ch = getchar();
        switch (suit_ch)
        {
        case 'c':
            suit = 0;
            break;
        case 'd':
            suit = 1;
            break;
        case 'h':
            suit = 2;
            break;
        case 's':
            suit = 3;
            break;
        }
        getchar();
        num_in_rank[rank]++;
        num_in_suit[suit]++;
        cards_read++;
        
    }
}

/* while (cards_read < NUM_CARDS) */
/* void read_cards(void) */
void analyze_hand(int rank,int suit)
{
    int num_consec = 0;
    
    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;
    int flag;
    /* check for flush */
    for (int i = 0; i < NUM_SUITS; i++)
        if (num_in_suit[i] == NUM_CARDS)
            flush = true;
        
    /* check for straight */
     int i = 0;
    while (num_in_rank[i] == 0)
        i++; /* find 1st nonzero */
    for (; i < NUM_RANKS && num_in_rank[i] > 0; i++)
        num_consec++;
    if (num_consec == NUM_CARDS)
    {
        straight = true;
        return;
    }
    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    for (int i = 0; i < NUM_RANKS; i++)
    {
        if (num_in_rank[i] == 4)
            four = true;
        if (num_in_rank[i] == 3)
            three = true;
        if (num_in_rank[i] == 2)
            pairs++;
    }
}
int print_result(void)
{
    if (straight && flush)
    {
        
        return 9;
    }
    else if (four)
    {

        return 8;
    }
    else if (three &&
             pairs == 1)
    {

        return 7;
    }
    else if (flush)
    {

        return 6;
    }
    else if (straight)
    {

        return 5;
    }
    else if (three)
    {

        return 4;
    }
    else if (pairs == 2)
    {

        return 3;
    }
    else if (pairs == 1)
    {

        return 2;
    }
    else
    {

        return 1;
    }
    printf("\n");
}