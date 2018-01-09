#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main()
{
    //I don't know why the book says to use an array
    //since i don't know the length of the sentence that the user might enter, i can't create an array
    char input;

    printf("Enter message: ");

    do
    {
        input = toupper(getchar());
        switch (input)
        {
            case 'A':
                putchar('4');
                break;
            case 'B':
                putchar('8');
                break;
            case 'E':
                putchar('3');
                break;
            case 'I':
                putchar('1');
                break;
            case 'O':
                putchar('0');
                break;
            case 'S':
                putchar('5');
                break;
            case '\n':
                break;
            default:
                putchar(input);
                break;
        }

    } while(input != '\n');

    for (int i = 0; i < 10; i++)
        putchar('!');

    return 0;
}
