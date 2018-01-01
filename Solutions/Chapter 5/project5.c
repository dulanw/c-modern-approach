#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    float Income;

    printf("Enter amount of taxable income : ");
    scanf("%f", &Income);

    //I used the <= for the upper limit since the first one says "Not Over 750"
    //the rest overlaps with their upper and lower limits
    float taxAmount;
    if (Income <= 750.f)
    {
        taxAmount = 0.01 * Income;
    }
    else if (Income <= 2250.f)
    {
        taxAmount = 7.50f + ((Income-750.f) * 0.02);
    }
    else if (Income <= 3750.f)
    {
        taxAmount = 37.50f + ((Income-2250.f) * 0.03);
    }
    else if (Income <= 5250.f)
    {
        taxAmount = 82.50f + ((Income-3750.f) * 0.04);
    }
    else if (Income <= 7000.f)
    {
        taxAmount = 142.50f + ((Income-5250.f) * 0.05);
    }
    else
    {
        taxAmount = 230.f + ((Income-7000.f) * 0.06);
    }

    printf("Tax due: %.2f", taxAmount);

    return 0;
}
