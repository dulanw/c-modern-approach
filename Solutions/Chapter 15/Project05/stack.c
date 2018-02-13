#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define STACK_SIZE 10

/*external variables */
char stack_contents[STACK_SIZE];
int stack_top = 0;

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

void stack_push(int i)
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

int stack_pop()
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
