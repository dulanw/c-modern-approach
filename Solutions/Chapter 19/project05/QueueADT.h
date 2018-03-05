#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

Queue create();
void destroy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
bool is_full(Queue q);
void push(Queue s, Item q);
Item pop(Queue q);
Item get_first(Queue q);
Item get_last(Queue q);
void print(Queue q);

#endif
