#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

bool play_game();
int roll_dice();

int main(void)
{

    // The maximum number that can be calculated with int is 2147395600
    //46340 squared is 2147395600 afterward it overflows and goes into the negative

    srand((unsigned) time(NULL));

    char playAgain;
    do
    {
        if (play_game())
        {
            printf("You Win!\n");
        }
        else
        {
            printf("You Lose!\n");
        }
        printf("\nPlay again? ");
        playAgain = toupper(getchar());
        while (getchar() != '\n');
        printf("\n");

    } while (playAgain == 'Y');


    return 0;
}

bool play_game()
{
    int firstRoll = roll_dice(), secondRoll;
    printf("You rolled: %d\n", firstRoll);

    if (firstRoll == 7 || firstRoll == 11)
    {
        return true;
    }
    else if (firstRoll == 2 || firstRoll == 3 || firstRoll == 12)
    {
        return false;
    }
    else
    {
        printf("Your point is %d\n", firstRoll);
        while (true)
        {
            secondRoll = roll_dice();
            printf("You rolled: %d\n", secondRoll);

            if (secondRoll == firstRoll)
            {
                return true;
            }
            else if(secondRoll == 7)
            {
                return false;
            }
        }
    }

}

int roll_dice()
{
    int die1, die2;
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    return die1 + die2;
}
