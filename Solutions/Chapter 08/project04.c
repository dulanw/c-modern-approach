#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 10

int main()
{
    int a[N];

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        scanf("%d", &a[i]);
    }

    printf("In reverse order: ");
    for (int i = (sizeof(a) / sizeof(a[0])) - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
