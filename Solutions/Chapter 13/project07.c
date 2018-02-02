#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//im using the date format dd/mm/yy instead of the one that is used in the book which might be the american format of mm/dd/yy
//just cause it confuses me
int main(void)
{
    int number;


    printf("Enter a two-digit number: ");
    scanf("%d", &number);


    printf("You entered the number ");

    if (number == 0)
    {
        printf("Zero");
    }

    else if( number >= 10 && number <= 19)
    {

        char * numbers[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
        printf("%s\n", numbers[number-10]);
    }

    else
    {
        char * numbers1[] = {"","","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
        char * numbers2[] = {"","one","two","three","four","five","six","seven","eight","nine"};
        int digit1 = number/10;
        int digit2 = number%10;

        printf("%s", numbers1[digit1]);

        if(digit2 != 0 && digit1 != 0)
        {
            printf("-");
        }

        printf("%s\n", numbers2[digit2]);

    }

    return 0;
}
