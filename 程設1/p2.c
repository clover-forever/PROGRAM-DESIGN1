#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_PLAYERS 4
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
/* external variables */

int num_in_rank[NUM_PLAYERS][NUM_RANKS];
int num_in_suit[NUM_PLAYERS][NUM_SUITS];
bool straight[NUM_PLAYERS], flush[NUM_PLAYERS], four[NUM_PLAYERS], three[NUM_PLAYERS];
int pairs[NUM_PLAYERS]; /* can be 0, 1, or 2 */
void read_cards(int i);
void analyze_hand(int i);
int print_result(int i);
int main(int i)
{
    for (int i=0;i<4;i++)
    {
        read_cards(i);
        analyze_hand(i);
        print_result(i);
          
    }
    int A,B,C,D;
    
    if (A>=B&&B>=C&&C>=D){
        printf("A B C D");
    }
    else if(A>=C&&C>=B&&B>=D){
        printf("A C B D");
    }
    else if(A>=C&&C>=D&&D>=B){
        printf("A C D B");
    }
    else if(A>=B&&B>=D&&D>=C){
        printf("A B D C");
    }
    else if(A>=D&&D>=B&&B>=C){
        printf("A D B C");
    }
    else if(A>=D&&D>=C&&C>=B){
        printf("A D C B");
    }
    else if(B>=A&&A>=C&&C>=D){
        printf("B A C D");
    }
    else if(B>=A&&A>=D&&D>=C){
        printf("B A D C");
    }
    else if(B>=C&&C>=A&&A>=D){
        printf("B C A D");
    }
    else if(B>=C&&C>=D&&D>=A){
        printf("B C D A");
    }
    else if(B>=D&&D>=A&&A>=C){
        printf("B D A C");
    }
    else if(B>=D&&D>=C&&C>=A){
        printf("B D C A");
    }
    else if(C>=A&&A>=B&&B>=D){
        printf("C A B D");
    }
    else if(C>=A&&A>=D&&D>=B){
        printf("C A D B");
    }
    else if(C>=B&&B>=A&&A>=D){
        printf("C B A D");
    }
    else if(C>=B&&B>=D&&D>=A){
        printf("C B D A");
    }
    else if(C>=D&&D>=A&&A>=B){
        printf("C D A B");
    }
    else if(C>=D&&D>=B&&B>=A){
        printf("C D B A");
    }
    else if(D>=A&&A>=C&&C>=B){
        printf("D A C B");
    }
    else if(D>=A&&A>=B&&B>=C){
        printf("D A B C");
    }
    else if(D>=B&&B>=A&&A>=C){
        printf("D B A C");
    }
    else if(D>=B&&B>=C&&C>=A){
        printf("D B C A");
    }
    else if(D>=C&&C>=A&&A>=B){
        printf("D C A B");
    }
    else if(D>=C&&C>=B&&B>=A){
        printf("D C B A");
    }
}
void read_cards(int i) // i = player num
{
    char rank_ch[4], suit_ch[4];
    int rank, suit;
    int cards_read;
    /* initialize */
    for (rank = 0;rank < NUM_RANKS; rank++)
    {
        num_in_rank[i][rank] = 0;
    }
    for (suit = 0; suit < NUM_SUITS; suit++)
        num_in_suit[i][rank] = 0;

    while (cards_read < NUM_CARDS)
    {
        rank_ch[i] = getchar();
        switch (rank_ch[i])
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
        suit_ch[i] = getchar();
        switch (suit_ch[i])
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
        num_in_rank[i][rank]++;
        num_in_suit[i][suit]++;
        cards_read++;
    }
}

/* while (cards_read < NUM_CARDS) */
/* void read_cards(void) */
void analyze_hand(int i)
{
    int num_consec[4];
    int rank, suit;
    straight[4] = false;
    flush[4] = false;
    four[4] = false;
    three[4] = false;
    pairs[4] = 0;
    /* check for flush */
    for (suit = 0; suit < NUM_SUITS; suit++)
        if (num_in_suit[i][suit] == NUM_CARDS)
            flush[i] = true;
    /* check for straight */
    rank = 0;
    while (num_in_rank[i][rank] == 0)
        rank++; /* find 1st nonzero */
    for (; rank < NUM_RANKS && num_in_rank[i][13] > 0; rank++)
        num_consec[i]++;
    if (num_consec[i] == NUM_CARDS)
    {
        straight[i] = true;
        return;
    }
    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    for (rank = 0; rank < NUM_RANKS; rank++)
    {
        if (num_in_rank[i][rank] == 4)
            four[i] = true;
        if (num_in_rank[i][rank] == 3)
            three[i] = true;
        if (num_in_rank[i][rank] == 2)
            pairs[i]++;
    }
}
int print_result(int i)
{
    if (straight[i] && flush[i]){
        printf("Straight flush");
        return 9;}
    if (four[i]){
        printf("Four of a kind");
        return 8;}
    if (three[i] &&
             pairs[i] == 1){
        printf("Full house");
        return 7;}
    if (flush[i]){
        printf("Flush");
        return 6;}
    if (straight[i]){
        printf("Straight");
        return 5;}
    if (three[i]){
        printf("Three of a kind");
        return 4;}
    if (pairs[i] == 2){
        printf("Two pairs");
        return 3;}
    if (pairs[i] == 1){
        printf("Pair");
        return 2;}
    else{
        printf("High card");
        return 1;}
    printf("\n");
}