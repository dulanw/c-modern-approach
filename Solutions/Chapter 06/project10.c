#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//im using the date format dd/mm/yy instead of the one that is used in the book which might be the american format of mm/dd/yy
//just cause it confuses me
int main(void)
{
    //variables to hold the earliest day
    int eDay = 0, eMonth = 0 , eYear = 0;

    //variables to store user input
    int inDay, inMonth, inYear;


    for (;;)
    {
        printf("Enter first date (dd/mm/yy): ");
        scanf("%d/%d/%d", &inDay, &inMonth, &inYear);

        if (inDay == 0 && inMonth == 0 && inYear == 0)
        {
            break;
        }
        else if (eDay == 0 && eMonth == 0 && eYear == 0)
        {
            eDay = inDay;
            eMonth = inMonth;
            eYear = inYear;
        }
        else
        {
            //compare the years first
            if (eYear == inYear)
            {
                //compare the months if the years are equal
                if(eMonth == inMonth)
                {
                    if (eDay > inDay)
                    {
                        eDay = inDay;
                        eMonth = inMonth;
                        eYear = inYear;
                    }
                }
                else if (eMonth > inMonth)
                {
                    eDay = inDay;
                    eMonth = inMonth;
                    eYear = inYear;
                }
            }
            else if (eYear > inYear)
            {
                eDay = inDay;
                eMonth = inMonth;
                eYear = inYear;
            }
        }
    }

    printf("%d/%d/%.2d is the earliest date\n", eDay, eMonth, eYear);


    return 0;
}
