#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 //maxmimum number of reminders
#define MSG_LEN 60 //max length of reminders

int read_line(char str[], int n);

int main()
{
    char reminders[MAX_REMIND][MSG_LEN + 12];
    char day_str[12], msg_str[MSG_LEN+1];
    int month, day, hours, minutes, i, j, num_remind = 0;

    for (;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("-- No space left --\n");
            break;
        }


        printf("Enter month/day, time, and reminder: ");
        scanf("%2d/%2d %2d:%2d", &month, &day, &hours, &minutes);

        if (month == 0)
            break;

        sprintf(day_str, "%2d/%2d %2d:%2d", month, day, hours, minutes);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;

        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay Time Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);
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
