#include <stdio.h>

int main(void)
{

    double e = 1;
    int number;
    float number2;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Enter a small floating-point number to which the current term is compared: ");
    scanf("%f", &number2);


    for (int i = 1; i <= number; i++)
    {
        int factorial = 1;
        for (int x = 1; x <= i; x++)
        {
            factorial *= x;
        }

        if((1.0f / factorial) < number2)
        {
            break;
        }

        e += (1.0f / factorial);
    }

    printf("e = %f\n", e);


    return 0;
}
