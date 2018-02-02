#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_PLANETS 9

int main(int argc, char const *argv[])
{
    char *planets[] = {"mercury", "venus", "earth", "marrs", "jupiter", "saturn", "uranus", "neptune", "pluto"};

    int i, j;

    for (i = 1; i < argc; i++)
    {
        char planet[strlen(argv[i] + 1)];

        strcpy(planet, argv[i]); //creating a copy of the command line argument so to not change the original
        strlwr(planet); //string library used to convert everything to lower case

        for (j = 0; j < NUM_PLANETS; j++)
        {
            if (strcmp(planet, planets[j]) == 0)
            {
                printf("%s is planet %d\n", argv[i], ++j);
                break;
            }
        }

        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }


    return 0;
}
