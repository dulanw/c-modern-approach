#include <stdio>

#define MAX_LENGTH 99

int main()
{
    printf("Enter a message: ");
    char message[MAX_LENGTH];
    int *index = &message;

    char input;

    while ((input = getchar()) != '\n' && index < &message[MAX_LENGTH])
    {
        *index = input;
        index++;
    }

    printf(" Reversal is: ");
    for (; index >= &message; index--)
        putchar(*index);

    putchar('\n');

    return 0;
}
