#include <stdio>
#include <stdbool>

#define MAX_LENGTH 100

int main()
{
    printf("Enter a message: ");
    char message[MAX_LENGTH];
    int *index = &message;
    int *first = &message;

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
        if(*index != *first)
        {
            palindrome = false;
            break;
        }
        --index;
        ++first;
    }

    if (palindrome)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}
