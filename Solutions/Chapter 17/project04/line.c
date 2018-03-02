#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"


#define MAX_LINE_LEN 60

struct node
{
    char character;
    struct node * next;
} * line = NULL;

int line_len = 0, num_words = 0;

void clear_line()
{
    struct node * cur = line, * prev = NULL;
    while (cur != NULL)
    {
        prev = cur;
        cur = cur->next;
        free(prev);
    }

    line = NULL;
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    struct node * cur, * new_node;

    //if line = NULL then cur will be null otherwise go to the last letter and being adding the chars from there.
    for (cur = line; cur != NULL && cur->next != NULL; cur = cur->next)
        ;

    //this will only be done if there is already char in line so no need to check if line is empty.
    if (num_words > 0)
    {
        new_node = malloc(sizeof(*new_node));

        new_node->character = ' ';
        new_node->next = NULL;

        cur->next = new_node;
        cur = new_node;

        line_len++;

    }

    for (int i = 0; i < strlen(word); i++)
    {
        new_node = malloc(sizeof(*new_node));

        if (!new_node)
        {
            printf("\nCould not allocate memory for character node\n");
            exit(EXIT_FAILURE);
        }

        new_node->character = word[i];
        new_node->next = NULL;

        if (!line && !cur)
        {
            line = new_node;
            cur = new_node;
        }
        else
        {
            cur->next = new_node;
            cur = new_node;
        }
    }

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
    struct node * cur;
    extra_spaces = space_remaining();

    for (cur = line; cur != NULL; cur = cur->next)
    {
        if (cur->character != ' ')
            putchar(cur->character);

        else
        {
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (j= 1; j <= spaces_to_insert + 1; j++)
                putchar(' ');

            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }
    putchar('\n');
}

void flush_line()
{
    if (line_len > 0)
        for (struct node * cur = line; cur != NULL; cur = cur->next)
            putchar(cur->character);

}
