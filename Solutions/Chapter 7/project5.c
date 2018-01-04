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
    int points = 0;

    printf("Enter phone number: ");


    do
    {
        //get char and conert to upper in one line.
        userInput =  toupper(getchar());

        //check if the character input int is less than or equal to the character value of 9
        //so the userinput is between 0-9 or its a - or random symbol then print it out

        //ASCII Codes table found here https://ascii.cl/ and http://en.cppreference.com/w/cpp/language/ascii
        //http://asciivalue.com/ was also helpful
        //character values for AEILNORSTU RSTU grouped together last
        //i could have also just done userinput == 'char' but already did it this way.
        if (userInput == 65 ||  userInput == 69 || userInput == 73 || userInput == 76 ||
        userInput == 78 || userInput == 79 || (userInput >= 82 && userInput <= 85))
            ++points;
        //DG
        else if (userInput == 68 || userInput == 71)
            points += 2;
        //BCMP
        else if (userInput == 66 ||  userInput == 67 || userInput == 77 || userInput == 80)
            points += 3;
        //FHVWY VWY grouped together last
        else if (userInput == 70 ||  userInput == 72 || (userInput >= 86 && userInput <= 89))
            points += 4;
        //K
        else if (userInput == 75)
            points += 5;
        //JX
        else if (userInput == 74 || userInput == 88)
            points += 8;
        //QZ
        else if (userInput == 81 || userInput == 90)
            points += 10;
    } while (userInput != '\n');

    printf("Scrabble value: %d", points);


    return 0;
}
