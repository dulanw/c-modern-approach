#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int read_line(char str[], int n);
void reverse(char *message);

int main()
{
    printf("Enter a message: ");
    char message[MAX_LENGTH + 1];
    read_line(message, MAX_LENGTH);

    reverse(message);

    printf(" Reversal is: ");
    printf("%s\n", message);

    return 0;
}

//cant think of any other way than using a temp char variable. ;(
void reverse(char *message)
{
    //get the end pointers
    char temp, *end = message + strlen(message) - 1;
    printf("message: %c, end: %c", *message, *end);

    while (message != end)
    {
        temp = *message;
        *message++ = *end;
        *end-- = temp;
    }
}

//return the number of characters read including the null character
int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    {
        if (i < n)
        {
            str[i++] = ch;
        }
    }

    str[i] = '\0';
    return i;
}
