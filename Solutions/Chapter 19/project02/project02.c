#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "StackADT.h"

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
    Stack s1 = create();
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
            push(s1, input - '0');
        }
        else if (input == '=')
        {
            printf("Value of expressin: %d", pop(s1));
            make_empty(s1);
            return;
        }
        else if (input == '+' || input == '-' || input == '*' || input == '/' )
        {
            int operand2 = pop(s1);
            int operand1 = pop(s1);
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

            push(s1, value);
        }
        else
        {
            printf("Invalid RPN expression\n");
            while (getchar() != '\n') ;
            make_empty(s1);
            return;
        }
    } while (input != '\n');
}
