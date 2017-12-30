#include <stdio.h>

#define TAXPERCENT 5

int main(void)
{
    float amount, total;

    printf("Enter an amount: ");
    scanf("%f", &amount);

    total = amount + (amount*TAXPERCENT/100);
    printf("With tax added: %.2f",total);

    return 0;
}
