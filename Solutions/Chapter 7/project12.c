#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main(void)
{
    //nextNum is the number that needs to be evaluated next after the operator + * / -
    float nextNum, result;
    char operator;

    printf("Enter an expression: ");

    scanf("%f", &result);
    //print all the letters except the spaces.
    //
    // while(getchar())

    while ((operator = getchar()) != '\n')
    {
        scanf("%f", &nextNum);

        switch (operator)
        {
            case '+':
                result += nextNum;
                break;
            case '-':
                result -= nextNum;
                break;
            case '*':
                result *= nextNum;
                break;
            case '/':
                result /= nextNum;
                break;
        }
    }

    printf("Value of expression: %g", result);

    return 0;
}
