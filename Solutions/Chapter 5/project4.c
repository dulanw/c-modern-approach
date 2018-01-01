#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    float windSpeed;

    printf("Enter wind speed in knots : ");
    scanf("%f", &windSpeed);

    if (windSpeed < 1.f)
    {
        printf("Calm");
    }
    else if (windSpeed <= 3.f)
    {
        printf("Light Air");
    }
    else if (windSpeed <= 27.f)
    {
        printf("Breeze");
    }
    else if (windSpeed <= 47.f)
    {
        printf("Gale");
    }
    else if (windSpeed <= 63.f)
    {
        printf("Storm");
    }
    else
    {
        printf("Hurricane");
    }

    return 0;
}
