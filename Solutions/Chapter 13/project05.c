#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int total = 0;
    /* code */
    for (int i = 1 - 1; i < argc; i++)
    {
        total += atoi(argv[i]);
    }

    printf("Total: %d\n", total);

    return 0;
}
