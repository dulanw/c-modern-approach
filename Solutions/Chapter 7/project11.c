#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//this doesn't compare the time for the previous day, only the current day so if the user enter 00:00,
//it will show the earliest depature for the current day which is 8:00am and not the 9:45 p.m. depature
//from the previous.

//http://unicode.org/reports/tr35/tr35-6.html#Date_Format_Patterns

int main(void)
{
    char firstLetter, input;

    printf("Enter a first and last name: ");
    scanf(" %c", &firstLetter);

    //skill all the other letters of the first name until we run into a space
    while (getchar() != ' ')
        ;

    //print all the letters except the spaces.
    while ((input = getchar()) != '\n')
    {
        if (input != ' ')
            putchar(input);
    }

    printf(", %c.\n", firstLetter);

    return 0;
}
