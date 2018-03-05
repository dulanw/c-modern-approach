#include <stdio.h>
#include "QueueADT.h"

int main()
{
    Queue s1;
    int n;

    s1 = create();

    push(s1, 1);
    print(s1);
    printf("------------\n");
    push(s1, 2);
    print(s1);
    printf("------------\n");

    n = pop(s1);
    print(s1);
    printf("------------\n");

    push(s1, 3);
    print(s1);
    printf("------------\n");
    push(s1, 2);
    print(s1);
    printf("------------\n");
    push(s1, 3);
    print(s1);
    printf("------------\n");
    push(s1, 3);
    print(s1);
    printf("------------\n");
    push(s1, 3);
    print(s1);
    printf("------------\n");
    push(s1, 3);
    print(s1);
    printf("------------\n");
    push(s1, 3);
    print(s1);
    printf("------------\n");

    return 0;
}
