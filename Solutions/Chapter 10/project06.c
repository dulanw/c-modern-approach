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
void stack_push(int i);
int stack_pop();
void stack_overflow();
void stack_underflow();

int main()
{
    for (;;)
    {
        run_calculator();
    }


    return 0;
}

void run_calculator()
{
    char input;
    printf("\nEnter an RPN expression: ");
    do
    {
        scanf(" %c", &input);
        if (input == 'q' || input == 'Q')
        {
            exit(EXIT_SUCCESS);
        }
        //check if its a number or not
        else if (input >= '0' && input <= '9')
        {
            //turn a char into its integer value
            //by taking away the value of '0'
            stack_push(input - '0');
        }
        else if (input == '=')
        {
            printf("Value of expressin: %d", stack_pop());
            stack_make_empty();
            return;
        }
        else if (input == '+' || input == '-' || input == '*' || input == '/' )
        {
            int operand2 = stack_pop();
            int operand1 = stack_pop();
            int value;
            switch (input)
            {
                case '+':
                    value = operand1 + operand2;
                    break;
                case '-':
                    value = operand1 - operand2;
                    break;
                case '*':
                    value = operand1 * operand2;
                    break;
                case '/':
                    value = operand1 / operand2;
                    break;
            }

            stack_push(value);
        }
        else
        {
            printf("Invalid RPN expression\n");
            while (getchar() != '\n') ;
            stack_make_empty();
            return;
        }
    } while (input != '\n');
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
