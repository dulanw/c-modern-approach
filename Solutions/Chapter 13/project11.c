#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LEN 100

//return the number of characters read including the null character
int read_line(char str[], int n);
double compute_average_word_length(const char * sentence);


int main(void)
{
    char sentence[MAX_LEN + 1];

    printf("Enter a sentence: ");
    read_line(sentence, MAX_LEN);



    printf("Average word length: %.2f", compute_average_word_length(sentence));

    return 0;
}


double compute_average_word_length(const char * sentence)
{
    float length = 0, numWords = 0;

    for (;;)
    {
        printf("current letter = %c, Length = %f, numWords= %f\n", *sentence, length, numWords);
        if (*sentence == ' ')
        {
            printf("found a space!\n");

            while (*sentence == ' ')
                sentence++;

            //length != 0 makes sure that if a user has a space at the front before the first word, it won't be counted as having 1 word before even the first alphabetical character is read.
            //if *sentence != '\0' is not used, then if the user leaves a space before the end of line, the null character will be read as a new word
            if (length != 0 && *sentence != '\0')
            {
                numWords++;
            }
        }

        else if (*sentence == '\0')
        {
            numWords++;
            break;
        }

        else
        {
            length++;
            sentence++;
        }

    }

    return (double) length/numWords;
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
