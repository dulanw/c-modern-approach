#include <stdio.h>
#include <stdlib.h>
#include "QueueADT.h"


struct queue_type
{
    Item * Content;
    int first_pos, last_pos, len;
};

static void terminate(const char * message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

static int get_next_pos(int current, Queue q)
{
    //next position to add the new item.
    int next_pos = current + 1;

    //check if last position, if its then circle around to the first position
    if (next_pos >= q->len)
        next_pos = 0;

    return next_pos;
}

Queue create(int QueueLen)
{
    Queue q = malloc(sizeof(*q));
    if (!q)
        terminate("Could not allocate memory for Queue\n");
    //-1 is used so to know when there are no items in the array.
    q->Content = malloc(sizeof(*(q->Content)) * QueueLen);

    if (!q->Content)
        terminate("Could not allocate memory for Queue Content\n");

    q->len = QueueLen;
    q->first_pos = -1;
    q->last_pos = -1;
    return q;
}

void destroy(Queue q)
{
    //make_empty(q); //no need to make empty since the content will be delete when free is called.
    free(q);
}


void make_empty(Queue q)
{
    while(!is_empty(q))
        pop(q);
}

bool is_empty(Queue q)
{
    return q->first_pos == -1;
}

bool is_full(Queue q)
{
    return get_next_pos(q->last_pos, q) == q->first_pos;
}

//i will do this in a circular way, so it doesn't shift all the content in the array
//by one when one is removed, instead it will move the first_pos and last_pos ints.
void push(Queue q, Item i)
{

    if (!is_full(q))
    {
        int next_pos = get_next_pos(q->last_pos, q);
        //setting the first pos to 0 if this is the first time an item is added
        if (q->first_pos == -1)
        {
            q->first_pos = 0;
        }

        q->Content[next_pos] = i;
        q->last_pos = next_pos;
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
        if (q->first_pos == q->last_pos)
            q->first_pos = q->last_pos = -1;

        else
            q->first_pos = get_next_pos(q->first_pos, q);
    }
    else
    {
        printf("Queue underflow\n");
    }
}

Item get_first(Queue q)
{
    return q->Content[q->first_pos];
}

Item get_last(Queue q)
{
    return q->Content[q->last_pos];
}

void print(Queue q)
{
    if (is_empty(q))
        return;

    int start = q->first_pos, end =  q->last_pos;
    for (;;)
    {
        printf("%d at position %d\n", q->Content[start], start);
        if (start == end)
            break;
        start = get_next_pos(start, q);
    }
}
