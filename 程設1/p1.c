#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define NUM_PLAYERS 4

enum cards_result
{
    straight_flush = 8,
    four_of_a_kind = 7,
    full_house = 6,
    flush_check = 5,
    straight_check = 4,
    three_of_a_kind = 3,
    two_pair = 2,
    one_pair = 1,
    high_card = 0
};

typedef struct card
{
    int rankk;
    int suitt;
} card;

struct card A[NUM_CARDS], B[NUM_CARDS], C[NUM_CARDS], D[NUM_CARDS];

int save[2][NUM_PLAYERS];
int num_in_rank[NUM_PLAYERS][NUM_RANKS];
int num_in_suit[NUM_PLAYERS][NUM_SUITS];
bool straight, flush, four, three;
int pairs;

void read_cards(int);
void analyze_hand(int);
int print_card();
void sort_player();
int check_value(struct card *, struct card *);
int cmp(const void *, const void *);

int main()
{
    for (int player = 0; player < NUM_PLAYERS; player++)
    {
        save[0][player] = player;
        read_cards(player);
        analyze_hand(player);
        save[1][player] += print_card();
    }
    sort_player();
}

void read_cards(int player)
{
    char rank_ch, suit_ch;
    int rank, suit;
    int cards_read = 0;
    int i = 0;
    /* initialize */
    for (rank = 0; rank < NUM_RANKS; rank++)
    {
        num_in_rank[player][rank] = 0;
    }
    for (suit = 0; suit < NUM_SUITS; suit++)
    {
        num_in_suit[player][suit] = 0;
    }
    while (cards_read < NUM_CARDS)
    {
        rank_ch = getchar();
        switch (rank_ch)
        {
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
        switch (player)
        {
        case 0:
            A[i].rankk = rank;
            A[i].suitt = suit;
            break;
        case 1:
            B[i].rankk = rank;
            B[i].suitt = suit;
            break;
        case 2:
            C[i].rankk = rank;
            C[i].suitt = suit;
            break;
        case 3:
            D[i].rankk = rank;
            D[i].suitt = suit;
            break;
        }
        getchar();
        num_in_rank[player][rank]++;
        num_in_suit[player][suit]++;
        // save[1][player] += 100*(rank+1) + suit+1;
        cards_read++;
        i++;
    }
}
void analyze_hand(int player)
{
    int num_consec = 0;
    int rank, suit;
    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;
    /* check for flush */
    for (suit = 0; suit < NUM_SUITS; suit++)
        if (num_in_suit[player][suit] == NUM_CARDS)
            flush = true;
    /* check for straight */
    rank = 0;
    while (num_in_rank[player][rank] == 0)
        rank++;
    /* find 1st nonzero */
    for (; rank < NUM_RANKS && num_in_rank[player][rank] > 0; rank++)
        num_consec++;
    if (num_consec == NUM_CARDS)
    {
        straight = true;
        return;
    }
    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    for (rank = 0; rank < NUM_RANKS; rank++)
    {
        if (num_in_rank[player][rank] == 4)
            four = true;
        if (num_in_rank[player][rank] == 3)
            three = true;
        if (num_in_rank[player][rank] == 2)
            pairs++;
    }
}
int print_card()
{
    if (straight && flush)
        return straight_flush;
    else if (four)
        return four_of_a_kind;
    else if (straight)
        return straight_check;
    else if (flush)
        return flush_check;
    else if (pairs == 1 && three)
        return full_house;
    else if (pairs == 0 && three)
        return three_of_a_kind;
    else if (pairs == 2)
        return two_pair;
    else if (pairs == 1)
        return one_pair;
    else
        return high_card;
}
void sort_player()
{
    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        for (int player = 0; player < NUM_PLAYERS - i - 1; ++player)
        {
            if (save[1][player] > save[1][player + 1])
            {
                int t = save[0][player];
                save[0][player] = save[0][player + 1];
                save[0][player + 1] = t;
                t = save[1][player];
                save[1][player] = save[1][player + 1];
                save[1][player + 1] = t;
            }
            int v;
            if (save[1][player] == save[1][player + 1])
            {
                if (save[0][player] == 0 && save[0][player + 1] == 1)
                    v = check_value(A, B);
                if (save[0][player] == 0 && save[0][player + 1] == 2)
                    v = check_value(A, C);
                if (save[0][player] == 0 && save[0][player + 1] == 3)
                    v = check_value(A, D);
                if (save[0][player] == 1 && save[0][player + 1] == 0)
                    v = check_value(B, A);
                if (save[0][player] == 1 && save[0][player + 1] == 2)
                    v = check_value(B, C);
                if (save[0][player] == 1 && save[0][player + 1] == 3)
                    v = check_value(B, D);
                if (save[0][player] == 2 && save[0][player + 1] == 0)
                    v = check_value(C, A);
                if (save[0][player] == 2 && save[0][player + 1] == 1)
                    v = check_value(C, B);
                if (save[0][player] == 2 && save[0][player + 1] == 3)
                    v = check_value(C, D);
                if (save[0][player] == 3 && save[0][player + 1] == 0)
                    v = check_value(D, A);
                if (save[0][player] == 3 && save[0][player + 1] == 1)
                    v = check_value(D, B);
                if (save[0][player] == 3 && save[0][player + 1] == 2)
                    v = check_value(D, C);
                if (v > 0)
                {
                    int t = save[0][player];
                    save[0][player] = save[0][player + 1];
                    save[0][player + 1] = t;
                    t = save[1][player];
                    save[1][player] = save[1][player + 1];
                    save[1][player + 1] = t;
                }
            }
        }
    }
    for (int player = NUM_PLAYERS - 1; player > -1; player--)
    {
        printf("%c ", save[0][player] + 'A');
    }
}
int cmp(const void *a, const void *b)
{
    struct card *aptr = (struct card *)a;
    struct card *bptr = (struct card *)b;
    if (aptr->rankk < bptr->rankk)
        return -1;
    if (aptr->rankk == bptr->rankk && aptr->suitt == bptr->suitt)
        return 0;
    if (aptr->rankk > bptr->rankk)
        return 1;
    if (aptr->rankk == bptr->rankk && aptr->suitt > bptr->suitt)
        return 1;
    if (aptr->rankk == bptr->rankk && aptr->suitt < bptr->suitt)
        return -1;
}
int check_value(struct card *a, struct card *b)
{
    qsort(a, 5, sizeof(struct card), cmp);
    qsort(b, 5, sizeof(struct card), cmp);
    if (a[4].rankk > b[4].rankk)
        return 1;

    else if (a[4].rankk == b[4].rankk)
    {
        if (a[4].suitt > b[4].suitt)
            return 1;
        if (a[4].suitt == b[4].suitt)
            return 0;
        if (a[4].suitt < b[4].suitt)
            return -1;
    }

    else
        return -1;
}