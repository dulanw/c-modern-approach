#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


//this doesn't compare the time for the previous day, only the current day so if the user enter 00:00,
//it will show the earliest depature for the current day which is 8:00am and not the 9:45 p.m. depature
//from the previous.
struct flight
{
    int depatureTime;
    int arrivalTime;
};

char * getTimeString(int timeInMinutes, char timeString[]);

int main(void)
{
    struct flight flights[] =
    {{8 * 60,       10 * 60 + 16},  {9 * 60 + 43,   11 * 60 + 52},
     {11 * 60 + 19, 13 * 60 + 31},  {12 * 60 + 47,  15 * 60},
     {14 * 60,      16 * 60 + 8},   {15 * 60 + 45,  17 * 60 + 55},
     {19 * 60,      21 * 60 + 20},  {21 * 60 + 45,  23 * 60 + 58}};
    int hours, minutes, timeInMinutes;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    //get how many minutes has passed since midnight
    timeInMinutes = (hours * 60) + minutes;


    int index, numOfFlights;
    numOfFlights = sizeof(flights)/sizeof(flights[0]);
    for (index = 0; index < numOfFlights - 1; index++)
    {
        //if not on the last one, while checking everything else
        if (abs(timeInMinutes - flights[index].depatureTime) <= abs(timeInMinutes - flights[index + 1].depatureTime))
            break;
    }

    //array to hold the time string, in the form of hh:mm AM or PM. which is 8 characters + 1 for null character
    char timeString[9] = "";
    printf("Cloest depature time is %s",getTimeString(flights[index].depatureTime, timeString));
    printf(", Arriving at %s.\n",  getTimeString(flights[index].arrivalTime, timeString));


    return 0;
}

//no need to pass in the length, we will always have a null character to know when the string ends.
char * getTimeString(int timeInMinutes, char timeString[])
{
    //clear the current string and add a null character to the start.
    strcpy(timeString, "");
    int hours24, minutes12, hours12;

    hours24 = timeInMinutes / 60;
    minutes12 = timeInMinutes % 60;

    if (hours24 == 0 || hours24 == 24)
        hours12 = 12;
    else if (hours24 > 12)
        hours12 = hours24%12;
    else
        hours12 = hours24;

    sprintf(timeString, "%d:%d ", hours12, minutes12);

    if (hours24 >= 0 && hours24 <12)
        strcat(timeString, "AM");
    else if (hours24 >= 12)
        strcat(timeString, "PM");

    return timeString;
}
