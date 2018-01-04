#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main(void)
{
    float length = 0, numWords = 0;
    char input;

    printf("Enter a sentence: ");

    for (;;)
    {
        input = getchar();

        if (input == ' ')
        {
            ++numWords;
            while (getchar() == ' ') ; //do nothing while reading the spaces
            ++length;
        }
        else if(input == '\n')
        {
            ++numWords;
            break;
        }
        else
        {
            ++length;
        }
    }

    ////// the method below also works but i prefer the one above since its more readable
    // while ((input = getchar()) != '\n')
    // {
    //     if (input == ' ')
    //     {
    //         ++numWords;
    //         while (getchar() == ' ') ; //do nothing while reading the spaces
    //         ++length;
    //     }
    //     else
    //     {
    //         ++length;
    //     }
    // }
    // ++numWords; //one word since the last word doesn't end with a space but rather a \n

    printf("Average word length: %.2f", (length/numWords));

    return 0;
}
