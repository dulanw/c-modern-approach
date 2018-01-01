#include <stdio.h>

int main(void)
{
    int number, digits;
    printf("Enter a number: ");
    scanf("%d", &number);

    if(number < 10)
    {
        digits = 1;
    }
    else if (number < 100)
    {
        digits = 2;
    }
    else if (number < 1000)
    {
        digits = 3;
    }
    else if (number < 10000)
    {
        digits = 4;
    }

    printf("the number %d has %d digits", number, digits);

    return 0;
}
