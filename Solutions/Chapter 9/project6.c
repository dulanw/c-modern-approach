#include <stdio.h>
#include <ctype.h>

int pow(int x, int power);
int calculate_poly(int x);

int main(void)
{

    // The maximum number that can be calculated with int is 2147395600
    //46340 squared is 2147395600 afterward it overflows and goes into the negative


    int x;

    printf("This program computes the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6\n");
    printf("Enter value for x: ");
    scanf("%d", &x);

    printf("Answer: %d\n", calculate_poly(x));


    return 0;
}

int calculate_poly(int x)
{
    int value;

    value = 3 * (pow(x,5)) + 2 * (pow(x,4)) - 5 * (pow(x,3)) - (pow(x,2)) - 7 * (pow(x,1)) - 6;
    return value;
}

int pow(int x, int power)
{
    if (power > 0)
    {
        return x * pow(x, power - 1);
    }
    else
    {
        return 1;
    }
}
