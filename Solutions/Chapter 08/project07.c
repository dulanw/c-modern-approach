#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main()
{
    int numbers[5][5];

    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
    {
        printf("Enter row %d: ", i + 1);
        //you can use a for loop here as well. doing  size of number[0]/number[0][0]
        //but doing this was is just easier
        scanf(" %d %d %d %d %d", &numbers[i][0], &numbers[i][1], &numbers[i][2], &numbers[i][3], &numbers[i][4]);
    }

    //row totals
    printf("\n Row totals:");
    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
    {
        int rowTotal = 0;
        for (int x = 0; x < sizeof(numbers[0])/sizeof(numbers[0][0]); x++)
        {
            rowTotal +=  numbers[i][x];
        }
        printf(" %d", rowTotal);
    }

    //column totals
    printf("\n Column totals:");
    for (int i = 0; i <  sizeof(numbers[0])/sizeof(numbers[0][0]); i++)
    {
        int columnTotal = 0;
        for (int x = 0; x < sizeof(numbers)/sizeof(numbers[0]); x++)
        {
            columnTotal +=  numbers[x][i];
        }
        printf(" %d", columnTotal);
    }


    return 0;
}
