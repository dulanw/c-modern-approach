/* maintains a parts database (array version) */

#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct parts
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

int find_part(int number, struct parts inventory[],  int num_parts);
void insert(struct parts inventory[],  int * num_parts);
void update(struct parts inventory[],  int num_parts);
void search(struct parts inventory[],  int num_parts);
void print(struct parts inventory[],  int num_parts);

//promts user to enter an operation code, then calls a function to perform the requested action
//rpeat until user enter the command q
int main()
{
    struct parts inventory[MAX_PARTS];

    int num_parts = 0; /*numnber of parts current stored*/

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
                insert(inventory, &num_parts);
                break;
            case 's':
                search(inventory, num_parts);
                break;
            case 'u':
                update(inventory, num_parts);
                break;
            case 'p':
                print(inventory, num_parts);
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
int find_part(int number, struct parts inventory[],  int num_parts)
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
void insert(struct parts inventory[],  int * num_parts)
{
    int part_number;

    if (*num_parts == MAX_PARTS)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number, inventory, *num_parts) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    inventory[*num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[*num_parts].on_hand);
    (*num_parts)++;

}

//allow user to look up part number and print info
void search(struct parts inventory[],  int num_parts)
{
    int i, part_number;

    printf("Enter part number: ");
    scanf("%d", &part_number);

    i = find_part(part_number, inventory, num_parts);

    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quanitity: %d\n", inventory[i].on_hand);
    }

    else
        printf("part not found.\n");
}

//allow user to update quanitity
void update(struct parts inventory[],  int num_parts)
{
    int i, part_number, change;

    printf("Enter part number: ");
    scanf("%d", &part_number);

    i = find_part(part_number, inventory, num_parts);

    if (i >= 0)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }

    else
        printf("part not found.\n");
}

//print inventory
void print(struct parts inventory[],  int num_parts)
{
    int i;
    printf( "Part number Part Name                    "
            "Quanitity on hand\n");
    for (i = 0; i < num_parts; i++)
    {
        printf("%7d     %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
    }
}
