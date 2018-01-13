#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int num1, num2;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    int n, m;
    if(num1 < num2)
    {
        n = num1;
        m = num2;
    }
    else
    {
        n = num2;
        m = num1;
    }

    if (n > 0 && m > 0)
    {
        while (n != 0)
        {
            int Remainder = m % n;
            m = n;
            n = Remainder;
        }
        printf("Greatest common divisor: %d", m);
    }
    else
    {
        printf("Input not Valid\n");
    }

    return 0;
}
