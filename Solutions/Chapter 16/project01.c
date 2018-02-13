#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct country_code
{
    char *country;
    int code;
};

//used the ones
const struct country_code country_codes[] =
{{"Argentina",              54}, {"Bangladesh",        880},
 {"Brazil",                 55}, {"Burma (Myanmar)",    95},
 {"China",                  86}, {"Colombia",           57},
 {"Congo, Dem. Rep. of",   243}, {"Egypt",              20},
 {"Ethiopia",              251}, {"France",             33},
 {"Germany",                49}, {"India",              91},
 {"Indonesia",              62}, {"Iran",               98},
 {"Italy",                  39}, {"Japan",              81},
 {"Mexico",                 52}, {"Nigeria",           234},
 {"Pakistan",               92}, {"Philippines",        63},
 {"Polan",                  48}, {"Russia",              7},
 {"South Africa",           27}, {"South Korea",        82},
 {"Spain",                  34}, {"Sudan",             249},
 {"Thailand",               66}, {"Turkey",             90},
 {"Ukraine",               380}, {"United Kingdom",     44},
 {"United States",           1}, {"Vietnam",            84}};

int main()
{
    int code;
    bool found = false;
    printf("Enter a international dialing code: ");
    scanf("%d", &code);


    //run loop while i < length of country_codes and not found. if found then end loop
    for (int i = 0; i < sizeof(country_codes) / sizeof(country_codes[0]) && !found; i++)
        if (country_codes[i].code == code)
        {
            found = true;
            printf("Corresponding country: %s\n", country_codes[i].country);
        }


    if (!found)
        printf("International dialing code is not valid!\n");



    return 0;
}
