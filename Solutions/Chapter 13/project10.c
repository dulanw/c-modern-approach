#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


//this doesn't compare the time for the previous day, only the current day so if the user enter 00:00,
//it will show the earliest depature for the current day which is 8:00am and not the 9:45 p.m. depature
//from the previous.

//http://unicode.org/reports/tr35/tr35-6.html#Date_Format_Patterns
#define MAX_LEN 100

void reverse_name(char *name);
int read_line(char str[], int n);

int main()
{
    char name[MAX_LEN + 1];

    printf("Enter a first and last name: ");
    read_line(name, MAX_LEN);
    reverse_name(name);
    printf("%s", name);

    // //skill all the other letters of the first name until we run into a space
    // while (getchar() != ' ')
    //     ;
    //
    // //print all the letters except the spaces.
    // while ((input = getchar()) != '\n')
    // {
    //     if (input != ' ')
    //         putchar(input);
    // }
    //
    // printf(", %c.\n", firstLetter);

    return 0;
}

void reverse_name(char *name)
{
    //there should only be 1 space between the first and last name
    //last name is a pointer to the start of last name;

    char firstname[2] = {name[0], '\0'}, *lastname;

    for (int i = 0;; i++)
    {
        if (name[i] == ' ')
        {
            lastname = &name[i+1];
            break;
        }
    }

    //this should be alright, the pointers are to the same array but it
    //is read 1 char at a time, and lastname will always be a few chars ahead
    strcpy(name, lastname);
    strcat(name, ", ");
    strcat(name, firstname);
    strcat(name, ".");
}

int read_line(char str[], int n)
{
    bool read_space = false;
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    {
        if (ch == ' ' && !read_space)
        {
            while ((ch = getchar()) == ' ')
            ;
        }

        //will only ignore spaces if it is before any characters, then it will start reading them
        read_space = true;

        if (i < n)
        {
            str[i++] = ch;
        }
    }

    str[i] = '\0';
    return i;
}
