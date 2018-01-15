#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int num1, num2;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num1, &num2);

    //this bit here is not really needed, realised it when i was going over it later on,
    //it doesn't matter which number is larger, but i just left it here, you can just have n = num2, m = num1
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
        num1 /= m;
        num2 /= m;
        printf("In lowest terms: %d/%d", num1, num2);
    }
    else
    {
        printf("Input not Valid\n");
    }

    return 0;
}
