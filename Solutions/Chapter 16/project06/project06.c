#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct date
{
    int day;
    int month;
    int year;
};

int noDaysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);
bool is_leap_year(int year);

//im using the date format dd/mm/yy instead of the one that is used in the book which might be the american format of mm/dd/yy
//just cause it confuses me
int main(void)
{
    struct date date1, date2;

    printf("Enter first date (dd/mm/yy): ");
    scanf("%d/%d/%d", &date1.day, &date1.month, &date1.year);

    printf("Enter second date (dd/mm/yy): ");
    scanf("%d/%d/%d", &date2.day, &date2.month, &date2.year);

    printf("number of days 1: %d, number of days 2: %d", day_of_year(date1), day_of_year(date2));

    if (compare_dates(date1, date2) < 0)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",  date1.day, date1.month, date1.year, date2.day, date2.month, date2.year);
    else if (compare_dates(date1, date2) > 0)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", date2.day, date2.month, date2.year, date1.day, date1.month, date1.year);
    else
        printf("%d/%d/%.2d is equal to %d/%d/%.2d\n", date2.day, date2.month, date2.year, date1.day, date1.month, date1.year);
    return 0;
}

int day_of_year(struct date d)
{
    int totalDays = 0;
    for (int i = 0; i < d.month - 1; i++)
    {
        totalDays += noDaysInMonth[i];

        //if it is a leap year and the month is february
        if (is_leap_year(d.year) && i == 1)
            totalDays++;
    }

    totalDays += d.day;
    return totalDays;
}

bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 &&year % 400 == 0);
}

int compare_dates(struct date d1, struct date d2)
{
    if (d1.year < d2.year)
        return -1;
    else if (d1.year > d2.year)
        return 1;
    else
    {
        const int d1_days = day_of_year(d1), d2_days = day_of_year(d2);
        if (d1_days < d2_days)
            return -1;
        else if (d1_days > d2_days)
            return 1;
        else
            return 0;
    }

}
