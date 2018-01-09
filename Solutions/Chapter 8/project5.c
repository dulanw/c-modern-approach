#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RATES ((int) (sizeof(value)/ sizeof(value[0])))
#define INITIAL_BALANCE 100.00


//you can verify the results of this program using this http://www.thecalculatorsite.com/finance/calculators/compoundinterestcalculator.php#compoundinterval
//set the Compound interval to monthly

int main()
{
    int i, lowest_rate, num_years, year;
    double value[5];

    printf("Enter annual interest rate: ");
    scanf("%d", &lowest_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++)
    {
        printf("%6d%%", lowest_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years; year++)
    {
        printf("%3d     ", year);
        for ( i = 0; i < NUM_RATES; i++)
        {
            for(int x = 0; x < 12; x++)
            {
                //divide this by 12 if you want the user to inter the yearly interest rate
                //I made the user enter the monthly interest rate
                value[i] += value[i] * (lowest_rate + i)/ 12 / 100.0f;
            }
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }


    return 0;
}
