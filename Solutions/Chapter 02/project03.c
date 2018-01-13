#include <stdio.h>
#define PI 3.14159

int main(void)
{
    float radius,volume;

    printf("Please Enter the radius of the sphere: ");
    scanf("%f",&radius);

    volume = (4.0f/3.0f)*PI*(radius*radius*radius);
    printf("Volume of a sphere with radius %.2f is %.2f",radius,volume);

    return 0;
}
