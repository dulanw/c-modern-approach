#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "StackADT.h"

int main()
{
    char input;
    Stack s1 = create();
    printf("\nEnter parentheses and/or braces: ");
    do
    {
        input = getchar();
        if (input == '{' || input == '(')
        {
            push(s1, input);
        }
        else if (input == '}' || input == ')')
        {
            char popped = pop(s1);
            if ((input == '}' && popped != '{') || (input == ')' && popped != '('))
            {
                printf("parentheses/braches are NOT nested properly\n");
                exit(EXIT_FAILURE);
            }
        }

    } while (input != '\n');

    printf("parentheses/braches are nested properly\n");

    return 0;
}
