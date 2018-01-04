#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(void)
{
    long long int factorial = 1; // change the data type for the different test cases
    //maximum factorial possible with even long long int is 25!
    int input; // keep this a int, can even be a short int since it doesn't need
               // go that high since the maximum possible with long long int is
               // to find 25!, anything higher than that cause overflow factorial

    printf("Enter a positive integer: ");
    scanf("%d", &input);

    //comment this line if you dont want see the table with the values
    for (int i = 1; i <= input; i++)
    {
        factorial *= i;
    }


    printf("Factorial of %d: %lld", input, factorial);

    return 0;
}
