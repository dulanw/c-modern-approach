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
} inventory[MAX_PARTS];

int num_parts = 0; /*numnber of parts current stored*/

int find_part(int number);
void insert();
void update();
void search();
void print();

void quicksort(struct parts a[], int low, int high);
int split(struct parts a[], int low, int high);

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

    printf("Enter part number: ");
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
    }

    else
        printf("part not found.\n");
}

//print inventory
void print()
{
    quicksort(inventory, 0, num_parts - 1);
    int i;
    printf( "Part number Part Name                      "
            "Quanitity on hand\n");
    for (i = 0; i < num_parts; i++)
    {
        printf("%7d     %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
    }
}

//done it here since its too much work to move the struct definition to its own header file.
void quicksort(struct parts a[], int low, int high)
{
    int middle;

    if (low >= high)
        return;

    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int split(struct parts a[], int low, int high)
{
    struct parts part_element = a[low];

    for (;;)
    {
        while (low < high && part_element.number <= a[high].number)
            high--;
        if (low >= high)
            break;
        a[low++] = a[high];

        while (low < high && a[low].number <= part_element.number)
            low++;

        if (low >= high)
            break;
        a[high--] = a[low];
    }

    a[high] = part_element;
    return high;
}
