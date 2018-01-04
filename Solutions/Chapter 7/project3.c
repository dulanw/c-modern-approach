#include <stdio.h>
#include <ctype.h>

int main(void)
{

    // The maximum number that can be calculated with int is 2147395600
    //46340 squared is 2147395600 afterward it overflows and goes into the negative
    // int store 4 bytes or 32 bits.
    // short store 2 bytes or 16 bits.
    // long store 4 bytes as well.


    double n, sum = 0;

    printf("This program sums a series of doubles.\n");
    printf("Enter doubles (0 to terminate): ");


    for (;;)
    {
        scanf("%lf", &n);

        if (n != 0)
        {
            sum += n;
        }
        else
        {
            break;
        }
    }

    printf("The sum is: %g", sum);



    return 0;
}
