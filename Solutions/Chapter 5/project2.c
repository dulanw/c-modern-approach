#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int hours24, minutes24, hours12;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours24, &minutes24);

    if (hours24 == 0 || hours24 == 24)
        hours12 = 12;
    else if (hours24 > 12)
        hours12 = hours24%12;
    else
        hours12 = hours24;

    if (hours24 >= 0 && hours24 <12)
    {
        printf("Equivalent 12-hour time: %d:%d AM\n", hours12, minutes24);
    }
    else if (hours24 >= 12)
    {
        printf("Equivalent 12-hour time: %d:%d PM\n", hours12, minutes24);
    }

    return 0;
}
