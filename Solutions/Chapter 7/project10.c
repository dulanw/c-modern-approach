#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//this doesn't compare the time for the previous day, only the current day so if the user enter 00:00,
//it will show the earliest depature for the current day which is 8:00am and not the 9:45 p.m. depature
//from the previous.

//http://unicode.org/reports/tr35/tr35-6.html#Date_Format_Patterns

int main(void)
{
    char input;
     int vowels = 0;

    printf("Enter a sentence: ");

    //trying a new way instead of doing a do-while loop
    while ((input = getchar()) != '\n')
    {
        input = toupper(input);
        switch (input)
        {
            case 'A': case 'E': case 'I': case 'O': case 'U':
             ++vowels;
        }
    }

    printf("Your sentence contains %d vowels\n", vowels);

    return 0;
}
