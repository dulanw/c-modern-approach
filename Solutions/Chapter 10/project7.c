#include <stdio.h>
#include <stdbool.h>

// I didn't follow what it said on the book since it's very confusing and I don't understand what they are trying to do.
//I stored the segements in an array on how it would be printed using _ and | to represent each different segement.
//I did not use process_digits because i wasn't sure what it was meant to do.
#define MAX_DIGITS 10
                               //0              1               2               3               4
char segements[10][7] = {{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},
                              //5               6               7               8               9
                         {1,0,1,1,0,1,1},{1,0,1,1,1,1,1},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
//I will convert the number from a char into an into by - '0';
int digits[MAX_DIGITS];
//how many digits are stored currently
int num_digits;

void clear_digits_array();
void print_digits_array();

int main(void)
{
    clear_digits_array();

    char input;

    printf("Enter a number: ");
    do
    {
        scanf("%c", &input);
        if (input >= '0' && input <= '9')
        {
            //this will turn the char into its properly int value.
            //since char 1 does give the int value 1, but decimal ascii value.
            digits[num_digits] = input - '0';
            printf("%d", digits[num_digits]);
            ++num_digits;
        }
    } while (input != '\n' && num_digits < MAX_DIGITS);

    if (num_digits > 0)
    {
        print_digits_array();
    }
    else
    {
        printf("\nNo digits found, please enter a number!\n");
    }

    return 0;
}

void clear_digits_array()
{
    num_digits = 0;
}

void print_digits_array()
{
    printf("\n");
    for (int digit = 0; digit < num_digits; digit++)
    {
        if (segements[digits[digit]][0])
            printf(" _ ");
        else
            printf("   ");

        printf("  ");
    }

    printf("\n");

    for (int digit = 0; digit < num_digits; digit++)
    {
        if (segements[digits[digit]][5])
            printf("|");
        else
            printf(" ");

        if (segements[digits[digit]][6])
            printf("_");
        else
            printf(" ");

        if (segements[digits[digit]][1])
            printf("|");
        else
            printf(" ");

        printf("  ");
    }

    printf("\n");

    for (int digit = 0; digit < num_digits; digit++)
    {
        if (segements[digits[digit]][4])
            printf("|");
        else
            printf(" ");

        if (segements[digits[digit]][3])
            printf("_");
        else
            printf(" ");

        if (segements[digits[digit]][2])
            printf("|");
        else
            printf(" ");

        printf("  ");
    }

    printf("\n");
}
