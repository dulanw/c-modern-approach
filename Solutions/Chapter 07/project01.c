#include <stdio.h>
#include <ctype.h>

int main(void)
{

    // The maximum number that can be calculated with int is 2147395600
    //46340 squared is 2147395600 afterward it overflows and goes into the negative


    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("%10d%10d\n", i, i * i);
    }

    return 0;
}
