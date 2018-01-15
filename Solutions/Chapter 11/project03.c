#include <stdio.h>
#include <stdbool.h>

void reduce(int numerator, int denominator, int * reduced_numerator, int * reduced_denominator);

int main(void)
{
    int numerator, denominator, reduced_numerator, reduced_denominator;

    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);



    if (numerator > 0 && denominator > 0)
    {
        reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);
        printf("In lowest terms: %d/%d", reduced_numerator, reduced_denominator);
    }
    else
    {
        printf("Input not Valid\n");
    }

    return 0;
}

void reduce(int numerator, int denominator, int * reduced_numerator, int * reduced_denominator)
{
    int n, m;

    m = numerator;
    n = denominator;

    while (n != 0)
    {
        int Remainder = m % n;
        m = n;
        n = Remainder;
    }
    *reduced_numerator = numerator / m;
    *reduced_denominator = denominator / m;
}
