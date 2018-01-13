#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//im using the date format dd/mm/yy instead of the one that is used in the book which might be the american format of mm/dd/yy
//just cause it confuses me
int main(void)
{
    int nGrade;

    printf("Enter numerical grade: ");
    scanf("%d", &nGrade);

    int digit = nGrade/10;

    if (nGrade <= 100 && nGrade >= 0)
    {
        switch (digit)
        {
            case 0: case 1: case 2: case 3: case 4: case 5:
                printf("Letter Grade: F\n");
                break;
            case 6:
                printf("Letter Grade: D\n");
                break;
            case 7:
                printf("Letter Grade: C\n");
                break;
            case 8:
                printf("Letter Grade: B\n");
                break;
            case 9: case 10:
                printf("Letter Grade: A\n");
                break;
            default:
                printf("Invalid Grade\n");
        }
    }
    else
    {
        printf("Invalid Grade, needs to be betwen 0-100\n");
    }


    return 0;
}
