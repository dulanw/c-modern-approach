#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    float value, commision;

    for (;;)
    {
        printf("\nEnter value of trade: ");
        scanf("%f", &value);

        if (value > 0)
        {
            if (value < 2500.00f)
            {
                commision = 30.f + 0.017f * value;
            }
            else if (value < 6250.00f)
            {
                commision = 56.f + 0.0066f * value;
            }
            else if (value < 20000.00f)
            {
                commision = 76.f + 0.0034 * value;
            }
            else if (value < 50000.00f)
            {
                commision = 100.f + 0.0022 * value;
            }
            else if (value < 500000.00f)
            {
                commision = 155.f + 0.0011 * value;
            }
            else
            {
                commision = 255.f + 0.0009 * value;
            }

            if (commision < 39.00f)
            {
                commision = 39.00f;
            }

            printf("Commision: $%.2f\n", commision);
        }
        else
            break;
    }

    return 0;
}
