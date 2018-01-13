#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(void)
{
    double x, y = 1, root, average; //initial guess of y is 1, x is user input number

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    //comment this line if you dont want see the table with the values
    printf("x\t\ty\t\tx/y\t\tAverage of y and x/y\n");

    for (;;)
    {
        root = x / y;
        average = (y + root) / 2;

        //comment this line if you dont want see the table with the values
        printf("%f\t%f\t%f\t%f\n", x, y , root, average);

        if (fabs(y - average) < 0.00001f)
        {
            break;
        }
        else
        {
            y = average;
        }
    }


    printf("Square root: %g", average);

    return 0;
}
