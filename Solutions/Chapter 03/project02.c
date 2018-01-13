#include <stdio.h>

int main(void)
{
    int itemNum,date,month,year;
    float unitPrice;

    printf("Enter item number: ");
    scanf("%d", &itemNum);

    printf("Enter unit price: ");
    scanf("%f", &unitPrice);

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &date, &year);


    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%d\t\t$%6.2f\t\t%d/%.2d/%d", itemNum, unitPrice, year, month, date);



    return 0;
}
