#include <stdio.h>
#include <ctype.h>

int main(void)
{

    printf("        size of int: %d\n", sizeof(int));
    printf("      size of short: %d\n", sizeof(short int));
    printf("       size of long: %d\n", sizeof(long int));
    printf("      size of float: %d\n", sizeof(float));
    printf("     size of double: %d\n", sizeof(double));
    printf("size of long double: %d\n", sizeof(long double));

    return 0;
}
