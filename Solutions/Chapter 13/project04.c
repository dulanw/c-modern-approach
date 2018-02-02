#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /* code */
    for (int i = argc - 1; i > 0; i--)
    {
        printf("%s ", argv[i]);
    }

    printf("\n");

    return 0;
}
