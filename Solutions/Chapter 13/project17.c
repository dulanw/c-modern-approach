#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

//not going to use the read_line function for this, the one i previously used is good enough
bool is_palindrom(const char *message);

int main()
{
    printf("Enter a message: ");
    char message[MAX_LENGTH + 1], input, * index = message;

    while ((input = getchar()) != '\n' && index < &message[MAX_LENGTH])
    {
        input = toupper(input);
        if (input >= 'A' && input <= 'Z')
        {
            *index = input;
            index++;
        }
    }
    //added this line just so i can get the length of the message properly. without the null characters cant use strlen
    *index = '\0';

    if (is_palindrom(message))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}

bool is_palindrom(const char *message)
{
    char * last = &message[strlen(message) - 1], * first = message;

    bool palindrome = true;
    while (last > first)
    {
        if(*last-- != *first++)
        {
            palindrome = false;
            break;
        }
    }

    return palindrome;
}
