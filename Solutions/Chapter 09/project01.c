#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

//WARNING
//Microsoft compiler does not support all of c99, variable length arrays (VLAs) is not supported.

void selection_sort(int n, int digit[]);

int main()
{
    int digit[5] = {0}, n;
    n = sizeof(digit) / sizeof(digit[0]) - 1;

    for (int x = 0; x < sizeof(digit) / sizeof(digit[0]); x++)
    {
            printf("Enter digit %d: ", x + 1);
            scanf("%d", &digit[x]);
    }

    selection_sort(n, digit);

    printf("\n");
    for (int x = 0; x < sizeof(digit) / sizeof(digit[0]); x++)
    {
            printf("%d ", digit[x]);
    }

    return 0;
}

void selection_sort(int n, int digit[5])
{
    int largest, temp, largestIndex;
    largest = digit[0];
    for (int x = 0; x <= n; x++)
    {
        if (largest <= digit[x])
        {
            largest = digit[x];
            largestIndex = x;
        }
    }

    temp = digit[n];
    digit[n] = digit[largestIndex];
    digit[largestIndex] = temp;

    if (n > 0)
    {
        selection_sort((n-1), digit);
    }

}
