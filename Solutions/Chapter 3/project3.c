#include <stdio.h>

int main(void)
{
    int GS1, Group, Publisher, Item, Check;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &GS1, &Group, &Publisher, &Item, &Check);

    printf("GS1 prefix: %d\n", GS1);
    printf("Group identifier: %d\n", Group);
    printf("Publisher code: %d\n", Publisher);
    printf("Item number: %d\n", Item);
    printf("Check digit: %d\n", Check);

    return 0;
}
