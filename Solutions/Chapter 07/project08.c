#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//this doesn't compare the time for the previous day, only the current day so if the user enter 00:00,
//it will show the earliest depature for the current day which is 8:00am and not the 9:45 p.m. depature
//from the previous.

//http://unicode.org/reports/tr35/tr35-6.html#Date_Format_Patterns

int main(void)
{
    int hours, minutes, timeInMinutes;
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


    //get how many minutes has passed since midnight
    timeInMinutes = (hours * 60) + minutes;

    //compare the time between 8am depature and 9:43 am depature
    //if it is closer to 8am depature then print,
    //else go to compare time between 9:43am depature and 11:19am depature
    if (abs(timeInMinutes - (8 * 60)) <= abs(timeInMinutes - (9 * 60 + 43)))
    {
        printf("Closest depature time is 8:00 a.m., arriving at 10:16 a.m.");
    }
    //compare time between 9:43am depature and 11:19am depature else compare next depature
    else if (abs(timeInMinutes - (9 * 60 + 43)) <= abs(timeInMinutes - (11 * 60 + 19)))
    {
        printf("Closest depature time is 9:43 a.m., arriving at 11:52 a.m.");
    }
    //compare time between 11:19am depature and 12:47am depature else compare next depature
    else if (abs(timeInMinutes - (11 * 60 + 19)) <= abs(timeInMinutes - (12 * 60 + 47)))
    {
        printf("Closest depature time is 11:19 a.m., arriving at 1:31 p.m.");
    }
    //compare time between 12:47am depature and 2:00pm depature else compare next depature
    else if (abs(timeInMinutes - (12 * 60 + 47)) <= abs(timeInMinutes - (14 * 60)))
    {
        printf("Closest depature time is 12:47 p.m., arriving at 3:00 p.m.");
    }
    //compare time between 2:00pm depature and 3:45pm depature else compare next depature
    else if (abs(timeInMinutes - (14 * 60)) <= abs(timeInMinutes - (15 * 60 + 45)))
    {
        printf("Closest depature time is 2:00 p.m., arriving at 4:08 p.m.");
    }
    //compare time between 3:45pm depature and 7:00pm depature else compare next depature
    else if (abs(timeInMinutes - (15 * 60 + 45)) <= abs(timeInMinutes - (19 * 60)))
    {
        printf("Closest depature time is 3:45 p.m., arriving at 5:55 p.m.");
    }
    //compare time between 7:00pm depature and 9:45pm depature else compare next depature
    else if (abs(timeInMinutes - (19 * 60)) <= abs(timeInMinutes - (21 * 60 + 45)))
    {
        printf("Closest depature time is 7:00 p.m., arriving at 9:20 p.m.");
    }

    else
    {
        printf("Closest depature time is 9:45 p.m., arriving at 11:58 p.m.");
    }


    return 0;
}
