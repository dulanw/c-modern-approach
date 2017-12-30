#include <stdio.h>

int main(void)
{
    int num1, num2, denom1, denom2, resultnum, resultdenom;
    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);

    resultnum = num1*denom2 + num2*denom1;
    resultdenom = denom1*denom2;

    printf("The sum is %d/%d", resultnum, resultdenom);


    return 0;
}
