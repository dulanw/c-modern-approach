#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 10

/*external variables */
char stack_contents[STACK_SIZE];
int stack_top = 0;

void stack_make_empty();
bool stack_is_empty();
bool stack_is_full();
void stack_push(char i);
char stack_pop();
void stack_overflow();
void stack_underflow();

int main()
{
    char input;
    printf("\nEnter parentheses and/or braces: ");
    do
    {
        input = getchar();
        if (input == '{' || input == '(')
        {
            stack_push(input);
        }
        else if (input == '}' || input == ')')
        {
            char popped = stack_pop();
            printf("popped: %c\n", popped);
            printf("input: %c\n", input);
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


void stack_make_empty()
{
    stack_top = 0;
}

bool stack_is_empty()
{
    return stack_top == 0;
}

bool stack_is_full()
{
    return stack_top == STACK_SIZE;
}

void stack_push(char i)
{
    if (stack_is_full())
    {
        stack_overflow();
    }
    else
    {
        stack_contents[stack_top++] = i;
    }
}

char stack_pop()
{
    if (stack_is_empty())
    {
        stack_underflow();
    }
    else
    {
        return stack_contents[--stack_top];
    }
}

void stack_overflow()
{
    printf("Stack overflow!\n");
    exit(EXIT_FAILURE);
}
void stack_underflow()
{
    printf("Stack underflow!\n");
    exit(EXIT_FAILURE);
}
