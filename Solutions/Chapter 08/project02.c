#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>


int main()
{
    int digit_seen[10] = {0}, digit;
    long long int n;

    printf("Enter a number: ");
    scanf("%lld", &n);

    while (n > 0)
    {
        digit = n % 10;
        ++digit_seen[digit];
        n /= 10;
    }

    printf("digit(s):\t0  1  2  3  4  5  6  7  8  9\n");
    printf("Occurrences:\t");

    for (int x = 0; x < sizeof(digit_seen) / sizeof(digit_seen[0]); x++)
    {
        printf("%d  ", digit_seen[x]);
    }

    return 0;
}
