#include <stdio.h>
#define PI 3.14159

int main(void)
{
    float radius = 10.0f;
    float volume = (4.0f/3.0f)*PI*(radius*radius*radius);
    printf("Volume of a sphere with radius %.1f is %.1f",radius,volume);
    return 0;
}
