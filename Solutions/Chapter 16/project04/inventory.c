/* maintains a parts database (array version) */

#include <stdio.h>
#include <ctype.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct parts
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
	float price;
} inventory[MAX_PARTS];

int num_parts = 0; /*numnber of parts current stored*/

int find_part(int number);
void insert();
void update();
void search();
void print();

//promts user to enter an operation code, then calls a function to perform the requested action
//rpeat until user enter the command q
int main()
{
    char code;

    for(;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;

        switch(code)
        {
            case 'i':
                insert();
                break;
            case 's':
                search();
                break;
            case 'u':
                update();
                break;
            case 'p':
                print();
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}

//return the index of the part number if found
//otherwise return -1
int find_part(int number)
{
    int i;

    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;

    //return -1 if not found
    return -1;
}

//allow the user to inert a new part
//if part already exist or database full returns error
void insert()
{
    int part_number;

    if (num_parts == MAX_PARTS)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number : ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
	printf("Enter price: ");
	scanf("%f", &inventory[num_parts].price);
    num_parts++;

}

//allow user to look up part number and print info
void search()
{
    int i, part_number;

    printf("Enter part number: ");
    scanf("%d", &part_number);

    i = find_part(part_number);

    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quanitity: %d\n", inventory[i].on_hand);
		printf("Price: %.2f\n", inventory[i].price);
    }

    else
        printf("part not found.\n");
}

//allow user to update quanitity
void update()
{
    int i, part_number, change;

    printf("Enter part number: ");
    scanf("%d", &part_number);

    i = find_part(part_number);

    if (i >= 0)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;

		char code;
		printf("Change price (y or n): ");
		scanf(" %c", &code);
		code = toupper(code);

		if (code == 'Y')
		{
			printf("Enter new price: ");
			scanf("%f", &inventory[i].price);
		}
    }

    else
        printf("part not found.\n");
}

//print inventory
void print()
{
    int i;
    printf( "Part number Part Name                "
            " Quanitity on hand Price\n");
    for (i = 0; i < num_parts; i++)
    {
        printf("%7d     %-25s %17d %.2f\n", inventory[i].number, inventory[i].name, inventory[i].on_hand, inventory[i].price);
    }

}
