#include <stdio.h>

int main(void)
{
    int num1, num2, denom1, denom2, resultNum, resultDenom;
    char operator;
    printf("Enter two fractions separated by a sign: ");
    scanf("%d/%d%c%d/%d", &num1, &denom1, &operator, &num2, &denom2);

    if (operator == '+')
    {
        resultNum = num1*denom2 + num2*denom1;
        resultDenom = denom1*denom2;
    }
    else if (operator == '-')
    {
        resultNum = num1*denom2 - num2*denom1;
        resultDenom = denom1*denom2;
    }
    else if (operator == '*')
    {
        resultNum = num1*num2;
        resultDenom = denom1*denom2;
    }
    else if (operator == '/')
    {
        resultNum = num1*denom2;
        resultDenom = denom1*num2;
    }

    printf("The answer is %d/%d", resultNum, resultDenom);


    return 0;
}
