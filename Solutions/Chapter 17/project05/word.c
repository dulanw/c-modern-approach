#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

int read_line(char str[], int n);
int compare_string(const void *p, const void *q);

int main()
{
    char word[MAX_WORD_LEN + 1], **words;
    int array_size = 10, num_words = 0;

    words = malloc(sizeof(*word) * array_size);
    for (;;)
    {
        //increase array by 10 everytime it gets full
        if (array_size == num_words)
        {

            char **new_words = realloc(words, sizeof(*words) * array_size + 10);

            if (new_words)
            {
                words = new_words;
                array_size += 10;
            }
            else
            {
                printf("List full, failed to allocate memeory for new array!");
                break;
            }
        }

        printf("Enter word: ");
        read_line(word, MAX_WORD_LEN);

        //if word length is zero, then break loop
        if (strlen(word) == 0)
            break;

        words[num_words] = malloc(sizeof(*word) * strlen(word) + 1);

        strcpy(words[num_words], word);
        num_words++;
    }

    qsort(words, num_words, sizeof(*words), compare_string);
    printf("\n");
    for (int i = 0; i < num_words; i++)
    {
        printf("%s ", words[i]);
    }
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;

    str[i] = '\0';
    return 0;
}

int compare_string(const void *p, const void *q)
{
    //p and q are a pointer to a pointer which
    const char **p1 = (const char **)p;
    const char **q1 = (const char **)q;
    return strcmp(*p1,*q1);
}
