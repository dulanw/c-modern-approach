#include <stdio.h>
#include <string.h>
#include <ctype.h>


//this doesn't compare the time for the previous day, only the current day so if the user enter 00:00,
//it will show the earliest depature for the current day which is 8:00am and not the 9:45 p.m. depature
//from the previous.

//http://unicode.org/reports/tr35/tr35-6.html#Date_Format_Patterns
#define MAX_LEN 100

int compute_vowel_count(const char * sentence);
int read_line(char str[], int n);

int main(void)
{
    char sentence[MAX_LEN];

    printf("Enter a sentence: ");
    read_line(sentence, MAX_LEN);

    printf("Your sentence contains %d vowels\n", compute_vowel_count(sentence));

    return 0;
}

int compute_vowel_count(const char * sentence)
{
    char input;
    int vowels = 0;

    //this can be done with while ((input = toupper(*sentence++)) != '\n')
    //but this was is a bit clearer what is happening.
    while (*sentence != '\0')
    {

        input = toupper(*sentence++);
        switch (input)
        {
            case 'A': case 'E': case 'I': case 'O': case 'U':
             vowels++;
        }
    }

    return vowels;
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
