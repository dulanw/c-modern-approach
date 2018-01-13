#include <stdio.h>


int main(void)
{
    //mrate = monthly rate, the rate divided by 100 then 12;
    float loan, rate, payement, balance, mrate;
    printf("Enter amount of loan: ");
    scanf("%f", &loan);

    printf("Enter interest rate (yearly): ");
    scanf("%f", &rate);

    printf("Enter monthly payement: ");
    scanf("%f", &payement);

    mrate = rate/100/12;
    balance = loan;

    // balance = balance + balance*mrate; should be moved above balance = balance - payment
    // if you want to see the answer like in the book, otherwise use this way since
    //  this is the way it is described but not shown in the book.

    balance = balance - payement;
    printf("Balance remaining after first payment: %.2f\n", balance);
    balance = balance + balance*mrate;

    balance = balance - payement;
    printf("Balance remaining after second payment: %.2f\n", balance);
    balance = balance + balance*mrate;

    balance = balance - payement;
    printf("Balance remaining after third payment: %.2f\n", balance);
    balance = balance + balance*mrate;

    return 0;
}
