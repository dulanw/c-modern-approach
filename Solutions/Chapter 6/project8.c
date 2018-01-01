#include <stdio.h>

int main(void)
{

    int noDays, currentDay;
    printf("Enter number of days in month: ");
    scanf("%d", &noDays);
    printf("Enter starting day of the week (1 = Sun, 7 = Sat): ");
    scanf("%d", &currentDay);

    for (int i = 1; i < currentDay; i++)
    {
        //print 2 spaces and another for the space between 2 days
        printf("   ");
    }

    for (int i = 1; i <= noDays; i++, currentDay++)
    {
        printf("%2d", i);

        if (currentDay%7 == 0)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }

    return 0;
}
