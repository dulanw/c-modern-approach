#include <stdio.h>

int main(void)
{
    int date,month,year;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",&month,&date,&year);
    printf("%d%.2d%d",year,month,date);

    return 0;
}
