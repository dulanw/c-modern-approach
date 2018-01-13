#include <stdio.h>

int main(void)
{
    //not sure if i should be using array here since it's not covered yet in the chapter
    int one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen,fourteen,fifteen,sixteen;

    printf("Enter the numbers from 1 to 16 in any order (space between numbers): ");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
    &one, &two, &three, &four, &five, &six, &seven, &eight, &nine, &ten, &eleven, &twelve, &thirteen, &fourteen, &fifteen, &sixteen);

    printf("%2d %2d %2d %2d\n", one, two, three, four);
    printf("%2d %2d %2d %2d\n", five, six, seven, eight);
    printf("%2d %2d %2d %2d\n", nine, ten, eleven, twelve);
    printf("%2d %2d %2d %2d\n", thirteen, fourteen, fifteen, sixteen);

    int rowsum1, rowsum2, rowsum3, rowsum4, colsum1, colsum2, colsum3, colsum4, diagsum1, diagsum2;
    rowsum1 =  one + two + three + four;
    rowsum2 =  five + six + seven + eight;
    rowsum3 =  nine + ten + eleven + twelve;
    rowsum4 =  thirteen + fourteen + fifteen + sixteen;

    colsum1 =  one + five + nine + thirteen;
    colsum2 =  two + six + ten + fourteen;
    colsum3 =  three + seven + eleven + fifteen;
    colsum4 =  four + eight + twelve + sixteen;

    diagsum1 =  one + six + eleven + sixteen;
    diagsum2 =  four + seven + ten + thirteen;

    printf("\nRow sums: %2d %2d %2d %2d\n", rowsum1, rowsum2, rowsum3, rowsum4);
    printf("Column sums: %2d %2d %2d %2d\n", colsum1, colsum2, colsum3, colsum4);
    printf("Diagonal sums: %2d %2d\n", diagsum1, diagsum2);

    return 0;
}
