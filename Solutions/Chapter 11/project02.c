#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//this doesn't compare the time for the previous day, only the current day so if the user enter 00:00,
//it will show the earliest depature for the current day which is 8:00am and not the 9:45 p.m. depature
//from the previous.
void find_closest_flight(int desired_time, int * depature_time, int * arrival_time);

//created this method just to print the time, it will just print AM or PM depending on the time passed in by value
void print_time(int input_time);

int main(void)
{
    int hours, minutes, desired_time, depature_time, arrival_time;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    //get how many minutes has passed since midnight
    desired_time = (hours * 60) + minutes;
    find_closest_flight(desired_time, &depature_time, &arrival_time);

    //compare the time between 8am depature and 9:43 am depature
    //if it is closer to 8am depature then print,
    //else go to compare time between 9:43am depature and 11:19am depature

    printf("Closest depature time is ");
    print_time(depature_time);
    printf(", arriving at ");
    print_time(arrival_time);

    return 0;
}

void find_closest_flight(int desired_time, int * depature_time, int * arrival_time)
{
    //THE PREVIOUS PRINTF MESSAGES HAS BEEN KEPT TO MAKE SURE THE TIMES MATCHES, NOT NEEDED ANYMORE
    if (abs(desired_time - (8 * 60)) <= abs(desired_time - (9 * 60 + 43)))
    {
        *depature_time = 8 * 60;
        *arrival_time = 10 * 60 + 16;
        //printf("Closest depature time is 8:00 a.m., arriving at 10:16 a.m.");
    }
    //compare time between 9:43am depature and 11:19am depature else compare next depature
    else if (abs(desired_time - (9 * 60 + 43)) <= abs(desired_time - (11 * 60 + 19)))
    {
        *depature_time = 9 * 60 + 43;
        *arrival_time = 11 * 60 + 52;
        //printf("Closest depature time is 9:43 a.m., arriving at 11:52 a.m.");
    }
    //compare time between 11:19am depature and 12:47am depature else compare next depature
    else if (abs(desired_time - (11 * 60 + 19)) <= abs(desired_time - (12 * 60 + 47)))
    {
        *depature_time = 11 * 60 + 19;
        *arrival_time = 13 * 60 + 31;
        //printf("Closest depature time is 11:19 a.m., arriving at 1:31 p.m.");
    }
    //compare time between 12:47am depature and 2:00pm depature else compare next depature
    else if (abs(desired_time - (12 * 60 + 47)) <= abs(desired_time - (14 * 60)))
    {
        *depature_time = 12 * 60 + 47;
        *arrival_time = 15 * 60;
        //printf("Closest depature time is 12:47 p.m., arriving at 3:00 p.m.");
    }
    //compare time between 2:00pm depature and 3:45pm depature else compare next depature
    else if (abs(desired_time - (14 * 60)) <= abs(desired_time - (15 * 60 + 45)))
    {
        *depature_time = 14 * 60;
        *arrival_time = 16 * 60 + 8;
        //printf("Closest depature time is 2:00 p.m., arriving at 4:08 p.m.");
    }
    //compare time between 3:45pm depature and 7:00pm depature else compare next depature
    else if (abs(desired_time - (15 * 60 + 45)) <= abs(desired_time - (19 * 60)))
    {
        *depature_time = 15 * 60 + 45;
        *arrival_time = 17 * 60 + 55;
        //printf("Closest depature time is 3:45 p.m., arriving at 5:55 p.m.");
    }
    //compare time between 7:00pm depature and 9:45pm depature else compare next depature
    else if (abs(desired_time - (19 * 60)) <= abs(desired_time - (21 * 60 + 45)))
    {
        *depature_time = 19 * 60;
        *arrival_time = 21 * 60 + 20;
        //printf("Closest depature time is 7:00 p.m., arriving at 9:20 p.m.");
    }

    else
    {
        *depature_time = 21 * 60 + 45;
        *arrival_time = 23 * 60 + 58;
        //printf("Closest depature time is 9:45 p.m., arriving at 11:58 p.m.");
    }
}

void print_time(int input_time)
{
    int hours24, minutes24, hours12;

    hours24 = input_time / 60;
    minutes24 = input_time % 60;

    if (hours24 == 0 || hours24 == 24)
        hours12 = 12;
    else if (hours24 > 12)
        hours12 = hours24%12;
    else
        hours12 = hours24;

    if (hours24 >= 0 && hours24 <12)
    {
        printf("%d:%.2d A.M.", hours12, minutes24);
    }
    else if (hours24 >= 12)
    {
        printf("%d:%.2d P.M.", hours12, minutes24);
    }
}
