#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main()
{
    printf("Enter a message: ");
    char message[MAX_LENGTH], *index = &message[0], *first = &message[0];
    char input;

    while ((input = getchar()) != '\n' && index < &message[MAX_LENGTH])
    {
        input = toupper(input);
        if (input >= 'A' && input <= 'Z')
        {
            *index = input;
            index++;
        }
    }

    bool palindrome = true;
    while (index > first)
    {
        //doing this first because index is 1 ahead of the actual index of the last entered
        //since its always increamented
        --index;
        if(*index != *first)
        {
            palindrome = false;
            break;
        }
        ++first;
    }

    if (palindrome)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}
