#include <stdio.h>
#include <ctype.h>

int main(void)
{

    // The maximum number that can be calculated with int is 2147395600
    //46340 squared is 2147395600 afterward it overflows and goes into the negative
    // int store 4 bytes or 32 bits.
    // short store 2 bytes or 16 bits.
    // long store 4 bytes as well.


    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    //read the \n char that is left behind when the user enter the number
    getchar("\n");

    for (i = 1; i <= n; i++)
    {
        printf("%10d%10d\n", i, i * i);
        if (i % 24 == 0)
        {
            printf("Press Enter to continue...");
            getchar("\n");
        }
    }

    return 0;
}
