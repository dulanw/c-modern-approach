#include <stdio.h>


int main(void)
{
    //mrate = monthly rate, the rate divided by 100 then 12;
    float loan, rate, payement, balance, mrate;
    int noPayments;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);

    printf("Enter interest rate (yearly): ");
    scanf("%f", &rate);

    printf("Enter monthly payement: ");
    scanf("%f", &payement);

    printf("Enter number of payments: ");
    scanf("%d", &noPayments);


    mrate = rate/100/12;
    balance = loan;

    // balance = balance + balance*mrate; should be moved above balance = balance - payment
    // if you want to see the answer like in the book, otherwise use this way since
    //  this is the way it is described but not shown in the book.

    for (int i = 1; i <= noPayments ; i++)
    {
        balance = balance - payement;
        printf("Balance remaining after payment %d: %.2f\n", i, balance);
        balance = balance + balance*mrate;
    }

    printf("Balance remaining after %d payments: %.2f\n", noPayments, balance);

    return 0;
}
