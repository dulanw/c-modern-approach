#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//this doesn't compare the time for the previous day, only the current day so if the user enter 00:00,
//it will show the earliest depature for the current day which is 8:00am and not the 9:45 p.m. depature
//from the previous.

//http://unicode.org/reports/tr35/tr35-6.html#Date_Format_Patterns

int main(void)
{
    int hours, minutes;
    char period;

    printf("Enter a 12-hour time (AM or PM): ");
    //space infront of %c means to skip zero or more white spaces.
    scanf("%d:%d %c", &hours, &minutes, &period);


    period = toupper(period);
    if (period == 'P')
        hours += 12;
    //check if the its midnight, i.e. 12AM and turn it into 00:00 in 24 hour format
    else if (period == 'A' && hours == 12)
        hours -= 12;
    else
    {
        printf("Please enter either AM or PM\n");
        return 0;
    }

    printf("Equivalent 24-hour time: %d:%.2d\n", hours, minutes);

    return 0;
}
