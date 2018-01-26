#include <stdio.h>

#define N 10

void max_min(int a[], int *max, int *min);

int main()
{
    int b[N], i, big, small;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &b[i]);

    max_min(b, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

void max_min(int a[], int *max, int *min)
{
    int * current;
    *max = *min = a[0];

    for (current = &a[1]; current < &a[N]; current++)
    {
        if (*current > *max)
            *max = *current;
        else if (*current < *min)
            *min = *current;
    }
}
