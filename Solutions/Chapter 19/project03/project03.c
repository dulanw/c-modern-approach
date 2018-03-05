#include <stdio.h>
#include "StackADT.h"

void printlen(char * name, Stack s);

int main()
{
    Stack s1, s2;
    int n;

    s1 = create();
    s2 = create();

    push(s1, 1);
    printlen("stack 1", s1);
    push(s1, 2);
    printlen("stack 1", s1);

    n = pop(s1);
    printf("Popped %d from s1\n", n);
    printlen("stack 1", s1);

    push(s2, n);
    printlen("stack 2", s2);

    n = pop(s1);
    printf("Popped %d from s1\n", n);
    printlen("stack 1", s1);

    push(s2, n);
    printlen("stack 2", s2);

    destroy(s1);

    while (!is_empty(s2))
    {
        printf("Popped %d from s2\n", pop(s2));
        printlen("stack 2", s2);
    }

    push(s2, 3);
    printlen("stack 2", s2);
    make_empty(s2);
    printlen("stack 2", s2);
    if (is_empty(s2))
        printf("s2 is empty\n");
    else
        printf("s2 is not empty\n");

    return 0;
}

void printlen(char * name, Stack s)
{
    printf("Length of %s is %d\n", name, length(s));
}
