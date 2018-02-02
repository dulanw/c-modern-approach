#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20

int read_line(char str[], int n);

int main()
{
    char input[MAX_LENGTH + 1], smallest[MAX_LENGTH + 1] = "", largest[MAX_LENGTH + 1] = "";  // + 1 to hold the null character

    do
    {
        printf("Enter word: ");
        read_line(input, MAX_LENGTH);

        if (strcmp(input, smallest) < 0)
            strcpy(smallest, input); // no need to use strcpy and include a null character at the end, input will always have a null characters

        if (strcmp(input, largest) > 0)
            strcpy(largest, input); // no need to use strcpy and include a null character at the end, input will always have a null characters

    } while (strlen(input) != 4);

    putchar('\n');
    printf("Smallest word: %s\nLargest word: %s", smallest, largest);

    return 0;
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
