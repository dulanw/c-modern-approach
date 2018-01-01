#include <stdio.h>

int main(void)
{

    double e = 1;
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);


    for (int i = 1; i <= number; i++)
    {
        int factorial = 1;
        for (int x = 1; x <= i; x++)
        {
            factorial *= x;
        }
        e += (1.0f / factorial);
    }

    printf("e = %f\n", e);


    return 0;
}
