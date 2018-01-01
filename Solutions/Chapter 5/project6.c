#include <stdio.h>

int main(void)
{
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
    printf("Enter the first 12 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12);

    int sum1 = n1 + n3 + n5 + n7 + n9 + n11;
    int sum2 = n2 + n4 + n6 + n8 + n10;
    int digit = 9 - ((((3 * sum1) + sum2) - 1) % 10);

    if(n12 == digit)
    {
        printf("VALID");
    }
    else
    {
        printf("NOT VALID");
    }


    return 0;
}
