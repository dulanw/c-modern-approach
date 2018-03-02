#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;

struct part * find_part(int number);
void insert();
void update();
void search();
void print();
void erase();

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
            case 'e':
                erase();
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }

    return 0;
}

struct part * find_part(int number)
{
    struct part *p;

    for(p = inventory; p != NULL && number > p->number; p = p->next)
        ;

    if (p!= NULL && number == p->number)
        return p;
    else
        return NULL;
}

void insert()
{
    struct part * cur, * prev, * new_node;

    new_node = malloc(sizeof(struct part));
    if (!new_node)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL; cur != NULL && new_node->number > cur->number;
        prev = cur, cur = cur->next)
        ;

    if (cur != NULL && new_node->number == cur->number)
    {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

void search()
{
    int part_number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &part_number);

    p = find_part(part_number);

    if (p)
    {
        printf("Part name: %s\n", p->name);
        printf("Quanitity: %d\n", p->on_hand);
    }

    else
        printf("part not found.\n");
}

void update()
{
    int part_number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &part_number);

    p = find_part(part_number);

    if (p)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    }

    else
        printf("part not found.\n");
}

void print()
{
    struct part * p;
    printf( "Part number Part Name                      "
            "Quanitity on hand\n");
    for (p = inventory; p != NULL; p = p->next)
    {
        printf("%7d     %-25s%11d\n", p->number, p->name, p->on_hand);
    }
}

void erase()
{
    struct part *cur, *prev;
    int part_number;

    printf("Enter part number: ");
    scanf("%d", &part_number);

    for (cur = inventory, prev = NULL; cur != NULL && part_number > cur->number;
        prev =  cur, cur = cur->next)
        ;

    if (cur != NULL && cur->number == part_number)
    {
        prev->next = cur->next;
        free(cur);
    }
    else
        printf("part not found.\n");
}
