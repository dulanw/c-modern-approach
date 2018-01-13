#include <stdio.h>
#include <ctype.h>
#include <time.h>

int pow(int x, int n);
int calculate_poly(int x);

int main(void)
{

    // The maximum number that can be calculated with int is 2147395600
    //46340 squared is 2147395600 afterward it overflows and goes into the negative


    int x, n;

    printf("Enter value for x: ");
    scanf("%d", &x);
    printf("Enter value for n: ");
    scanf("%d", &n);

    printf("Answer: %d\n", pow(x, n));


    return 0;
}


int pow(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        if (n % 2 == 0)
        {
            int value = pow(x, n/2);
            return value*value;
        }
        else
        {
            return x * pow(x, n - 1);
        }
    }
}
