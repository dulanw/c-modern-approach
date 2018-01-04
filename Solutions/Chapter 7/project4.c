#include <stdio.h>
#include <ctype.h>

int main(void)
{

    // The maximum number that can be calculated with int is 2147395600
    //46340 squared is 2147395600 afterward it overflows and goes into the negative
    // int store 4 bytes or 32 bits.
    // short store 2 bytes or 16 bits.
    // long store 4 bytes as well.

    char userInput;

    printf("Enter phone number: ");


    do
    {
        userInput =  getchar();

        //check if the character input int is less than or equal to the character value of 9
        //so the userinput is between 0-9 or its a - or random symbol then print it out
        if (userInput <= 57)
            putchar(userInput);

        //ASCII Codes table found here https://ascii.cl/ and http://en.cppreference.com/w/cpp/language/ascii
        // I decided to include some extra letter, since according to this https://www.miniwebtool.com/word-to-phone-number-converter/
        // the Q and Z was left out in the book.
        //if the input is between int value of ABC
        else if (userInput >= 65 && userInput <= 67)
            putchar('2');
        //if the input is between int value of DEF
        else if (userInput >= 68 && userInput <= 70)
            putchar('3');
        //if the input is between int value of GHI
        else if (userInput >= 71 && userInput <= 73)
            putchar('4');
        //if the input is between int value of JKL
        else if (userInput >= 74 && userInput <= 76)
            putchar('5');
        //if the input is between int value of MNO
        else if (userInput >= 77 && userInput <= 79)
            putchar('6');
        //if the input is between int value of PQRS
        else if (userInput >= 80 && userInput <= 83)
            putchar('7');
        //if the input is between int value of TUV
        else if (userInput >= 84 && userInput <= 86)
            putchar('8');
        //if the input is between int value of W-Z, decided to include Z as well since it was left out
        else if (userInput >= 87 && userInput <= 90)
            putchar('9');

    } while (userInput != '\n');

    return 0;
}
