#include <stdio.h>
#include <stdlib.h>
#include "QueueADT.h"

struct node
{
    Item data;
    struct node * next;
};

struct queue_type
{
    struct node * First, * Last;
};

static void terminate(const char * message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create()
{
    Queue q = malloc(sizeof(*q));
    if (!q)
        terminate("Could not allocate memory for Queue\n");

    q->First = NULL;
    q->Last = NULL;
    return q;
}

void destroy(Queue q)
{
    make_empty(q); //no need to make empty since the content will be delete when free is called.
    free(q);
}


void make_empty(Queue q)
{
    while(!is_empty(q))
        pop(q);
}

bool is_empty(Queue q)
{
    return q->First == NULL;
}

bool is_full(Queue q)
{
    return false;
}

//i will do this in a circular way, so it doesn't shift all the content in the array
//by one when one is removed, instead it will move the first_pos and last_pos ints.
void push(Queue q, Item i)
{

    if (!is_full(q))
    {
        struct node * new_node = malloc(sizeof(*new_node));
        if (!new_node)
            terminate("Could not allocate memory for node\n");
        else
        {
            new_node->data = i;
            new_node->next = NULL;

            if (q->First == NULL)
                q->First = new_node;
            else
                q->Last->next = new_node;

            q->Last = new_node;
        }
    }
    else
    {
        printf("Queue Overflow\n");
    }
}

Item pop(Queue q)
{
    if (!is_empty(q))
    {
        //set the first and last pos to -1 if there is only 1 items which is being removed.
        //and the array is empty
        struct node * old_node = q->First;

        //first will be set to null if there is no next node, since next node is set to NULL when created.
        //only points to something if there is a node afterward.
        q->First = old_node->next;
        free(old_node);
    }
    else
    {
        printf("Queue underflow\n");
    }
}

Item get_first(Queue q)
{
    return q->First->data;
}

Item get_last(Queue q)
{
    return q->Last->data;
}

void print(Queue q)
{
    if (is_empty(q))
        return;

    struct node * start;
    int i;
    for (start = q->First, i = 1; start != NULL; start = start->next, i++)
        printf("%d at position %d\n", start->data, i);
}
