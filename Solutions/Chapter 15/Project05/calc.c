#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void run_calculator();

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
