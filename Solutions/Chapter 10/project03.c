#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

//external variables
int hand[NUM_CARDS][2];
bool straight, flush, two_pairs;
int pairs; // can be 0, 1, or 2

//prototype
void read_cards();
void analyze_hand();
void print_result();

/*main: calls read_cards, analayze_hand and print_reuslt repeatedly*/
int main()
{
    for (;;)
    {
        read_cards();
        analyze_hand();
        print_result();
    }
}

void read_cards()
{
    bool bad_card, dup_card;
    char ch, rank_ch, suit_ch;
    int rank, suit;
    int cards_read = 0;

    for (int x = 0; x < NUM_CARDS; x++)
    {
        for (int y = 0; y < 2; y++)
            hand[x][y] = 0;
    }

    while (cards_read < NUM_CARDS)
    {
        bad_card = false;
        dup_card = false;

        printf("Enter a card: ");

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
                rank = 7;
                break;
            case '9':
                rank = 8;
                break;
            case 't':
            case 'T':
                rank = 9;
                break;
            case 'q':
            case 'Q':
                rank = 10;
                break;
            case 'k':
            case 'K':
                rank = 11;
                break;
            case 'a':
            case 'A':
                rank = 12;
                break;
            default:
                bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch)
        {
            case 'c':
            case 'C':
                suit = 0;
                break;
            case 'd':
            case 'D':
                suit = 1;
                break;
            case 'h':
            case 'H':
                suit = 2;
                break;
            case 's':
            case 'S':
                suit = 3;
                break;
            default:
                bad_card = true;
        }

        while ((ch = getchar()) != '\n')
        {
            if (ch != ' ')
            {
                bad_card = true;
            }
        }


        for (int x = 0; x < cards_read; x++)
        {
            if (hand[x][0] == rank && hand[x][1] == suit)
            {
                dup_card = true;
            }
        }

        if (bad_card)
        {
            printf("Bad card; ignored.\n");
        }
        else if (dup_card)
        {
            printf("Duplicate card; ignored.\n");
        }
        else
        {
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            cards_read++;
        }
    }
}

/*//////////////////////////////////////////////////////////////////////////////////////
//analyse hand: determines weather the hand contains a straight, a flush, four of a kind,
                and/or three-of-a-kind; determines the number of pairs; store the results
                into the external variables straight, flush, four, three, and pairs
*////////////////////////////////////////////////////////////////////////////////////////

void analyze_hand()
{
    //this is a counter to keep track of anything that needs a counter.
    //set it to 0 before checking for a flush or whatever.
    //int counter;
    straight = true;
    flush = true;
    pairs = 0;
    two_pairs = false;

    //check for flush
    //this meansn that all the cards should be equal in suit.
    //which also means that all the cards should be equal to the suit of the first hand
    //flush != false; no need to check the other cards if one of the cards are different.
    //also check if flush variable has changed
    for (int x = 0; x < NUM_CARDS && flush != false; x++)
    {
        //check
        if (hand[x][1] != hand[0][1])
        {
            flush = false;
        }
    }

    //check for straight and straight variable hasnt changed
    for (int x = 0; x < NUM_CARDS - 1 && straight != false; x++)
    {
        int rank_diff = hand[x+1][0] - hand[x][0];
        if (rank_diff != 1)
        {
            straight = false;
        }
    }

    int first_pair;
    //cehck for 4-of-a-kind, 3-of-a-kind, and pairs
    for (int x = 0; x < NUM_CARDS; x++)
    {
        bool found_pair = false;
        for (int y = x + 1; y < NUM_CARDS && !found_pair; y++)
        {
            if (hand[x][0] == hand[y][0])
            {
                if (pairs == 0)
                {
                    first_pair = hand[x][0];
                }
                else if (pairs > 0 && first_pair != hand[x][0])
                {
                    two_pairs = true;
                }
                pairs++;
                found_pair = true;
            }
        }
    }
}


void print_result()
{
    if (straight && flush) printf("Straight flush");
    else if (pairs == 3 && !two_pairs) printf("Four of a kind");
    else if (pairs == 3 && two_pairs) printf("Full house");
    else if (flush) printf("Flush");
    else if (straight) printf("Straight");
    else if (pairs == 2 && !two_pairs) printf("Three of a kind");
    else if (pairs == 2 && two_pairs) printf("Two pairs");
    else if (pairs == 1) printf("Pair");
    else printf("High card");

    printf("\n\n");
}
