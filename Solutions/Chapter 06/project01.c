#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    float input, largest = 0;

        printf("Enter a number: ");
        scanf("%f", &input);

        if (input > largest)
        {
            largest = input;
        }
    } while(input > 0);


    printf("The largest number entered was %f", largest);


    return 0;
}
