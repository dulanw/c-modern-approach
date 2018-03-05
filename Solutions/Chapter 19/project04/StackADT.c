#include <stdio.h>
#include <stdlib.h>
#include "StackADT.h"

struct node
{
    void * data;
    //i decided to call the pointer to the node previous, because it stores a pointer to the previous node
    //the way it is done in the book makes no sense.
    struct node * previous;
};

struct stack_type
{
    struct node * top;
};

static void terminate(const char * message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create()
{
    Stack s = malloc(sizeof(*s));
    if (!s)
        terminate("Could not allocate memory for Stack\n");
    s->top = NULL;
    return s;
}

void destroy(Stack s)
{
    make_empty(s);
    free(s);
}

void make_empty(Stack s)
{
    while(!is_empty(s))
        pop(s);
}

bool is_empty(Stack s)
{
    return s->top == NULL;
}

bool is_full(Stack s)
{
    return false;
}

void push(Stack s, void * p)
{
    struct node * new_node = malloc(sizeof(*new_node));
    if (!new_node)
        terminate("Stack overflow, Could not allocate memory for node\n");

    new_node->data = p;
    new_node->previous = s->top;
    s->top = new_node;
}

void * pop(Stack s)
{
    if (is_empty(s))
        terminate("Stack underflow\n");

    struct node * old_top = s->top;
    void * p = old_top->data;

    s->top = old_top->previous;
    free(old_top);
    return p;
}
