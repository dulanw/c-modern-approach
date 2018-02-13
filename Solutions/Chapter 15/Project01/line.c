#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "line.h"


#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
//lines variable is used to store how many lines have been printed
//used to switch between the two different types of spacing
int line_len = 0, num_words = 0, lines = 0;

void clear_line()
{
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    if (num_words > 0)
    {
        line[line_len] = ' ';
        line[line_len + 1] = '\0';
        line_len++;
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}

int space_remaining()
{
    return MAX_LINE_LEN - line_len;
}

void write_line()
{
    int extra_spaces, spaces_to_insert, i, j;
    extra_spaces = space_remaining();

    for (i = 0; i< line_len; i++)
    {
        if (line[i] != ' ')
            putchar(line[i]);

        else
        {
            //don't really know any other way to do this, ((extra_spaces - 1) / (num_words - 1)) + 1;
            //thats the easiest way i found to reverse how the words are spaced.
            if (extra_spaces > 0 && (lines%2) == 1 )
                spaces_to_insert = ((extra_spaces - 1) / (num_words - 1)) + 1;
            else
                spaces_to_insert = extra_spaces / (num_words - 1);

            //printf("\n extra_spaces = %d, extra_spaces - 1 = %d/%d = %d + 1 = %d\n", extra_spaces, (extra_spaces - 1), (num_words - 1), (extra_spaces - 1)/(num_words - 1), (extra_spaces - 1)/(num_words - 1) + 1);
            for (j= 1; j <= spaces_to_insert + 1; j++)
                putchar(' ');

            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }
    putchar('\n');

    //lines variable is used to store how many lines have been printed
    //used to switch between the two different types of spacing
    lines++;
}

void flush_line()
{
    if (line_len > 0)
        puts(line);
}
