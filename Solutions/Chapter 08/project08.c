#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main()
{
    int numbers[5][5];

    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
    {
        printf("Enter quiz marks for student %d: ", i + 1);
        //you can use a for loop here as well. doing  size of number[0]/number[0][0]
        //but doing this was is just easier
        scanf(" %d %d %d %d %d", &numbers[i][0], &numbers[i][1], &numbers[i][2], &numbers[i][3], &numbers[i][4]);
    }

    //row totals
    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
    {
        int rowTotal = 0;
        for (int x = 0; x < sizeof(numbers[0])/sizeof(numbers[0][0]); x++)
        {
            rowTotal +=  numbers[i][x];
        }
        float average = (float) rowTotal / (sizeof(numbers[0])/sizeof(numbers[0][0]));
        printf("\nTotal score for student %d: %d with an average score of: %.1f", i + 1, rowTotal, average);
    }

    //column totals
    printf("\n");
    for (int i = 0; i <  sizeof(numbers[0])/sizeof(numbers[0][0]); i++)
    {
        int columnTotal = 0;
        int highScore = numbers[0][i];
        int lowScore = numbers[0][i];
        for (int x = 0; x < sizeof(numbers)/sizeof(numbers[0]); x++)
        {
            columnTotal +=  numbers[x][i];
            if (highScore < numbers[x][i])
            {
                highScore = numbers[x][i];
            }

            if (lowScore > numbers[x][i])
            {
                lowScore = numbers[x][i];
            }
        }
        float average = (float) columnTotal / (sizeof(numbers)/sizeof(numbers[0]));
        printf("\nTest %d average is: %.1f, highest score is: %d, lowest score is: %d", i + 1, average, highScore, lowScore);
    }

    printf("\n");

    return 0;
}
