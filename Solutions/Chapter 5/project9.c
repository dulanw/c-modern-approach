#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//im using the date format dd/mm/yy instead of the one that is used in the book which might be the american format of mm/dd/yy
//just cause it confuses me
int main(void)
{
    int month1, day1, year1, month2, day2, year2;

    printf("Enter first date (dd/mm/yy): ");
    scanf("%d/%d/%d", &day1, &month1, &year1);

    printf("Enter second date (dd/mm/yy): ");
    scanf("%d/%d/%d", &day2, &month2, &year2);

    //compare the years first
    if (year1 == year2)
    {
        //compare the months if the years are equal
        if(month1 == month2)
        {
            //if years and months are the same, then compare the days
            if(day1 == day2)
            {
                printf("%d/%d/%.2d is equal to %d/%d/%.2d\n",  day1, month1, year1, day2, month2, year2);
            }
            else if (day1 < day2)
            {
                printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",  day1, month1, year1, day2, month2, year2);
            }
            else
            {
                printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",  day2, month2, year2, day1, month1, year1);
            }
        }
        else if (month1 < month2)
        {
            printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",  day1, month1, year1, day2, month2, year2);
        }
        else
        {
            printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",  day2, month2, year2, day1, month1, year1);
        }
    }
    else if (year1 < year2)
    {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",  day1, month1, year1, day2, month2, year2);
    }
    else
    {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",  day2, month2, year2, day1, month1, year1);
    }

    return 0;
}
