#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

//not going to use the read_line function for this, the one i previously used is good enough
bool is_palindrom(const char *message);

int main()
{
    printf("Enter a date (mm/dd/yyyy): ");
    int month, day, year;
    char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

    scanf("%2d/%2d/%4d", &month, &day, &year);

    printf("You entered the date %s %d, %d", months[month-1], day, year);


    return 0;
}
