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

    printf("Repeated digit(s): ");

    for (int x = 0; x < sizeof(digit_seen) / sizeof(digit_seen[0]); x++)
    {
        if (digit_seen[x] > 1)
        {
            printf("%d ", x);
        }

    }

    return 0;
}
