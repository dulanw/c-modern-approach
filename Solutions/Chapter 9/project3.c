#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define COLSIZE 10
#define ROWSIZE 10

void generate_random_walk(char walk[ROWSIZE][COLSIZE]);

void print_array(char walk[ROWSIZE][COLSIZE]);

int main()
{
    //I will be using 0,1,2,3 as N,E,S,W (UP, RIGHT, DOWN, LEFT)
    char array[ROWSIZE][COLSIZE];
    //the location that the current word is at.


    for (int y = 0; y < sizeof(array) / sizeof(array[0]); y++)
    {
        for (int x = 0; x < sizeof(array[0]) / sizeof(array[0][0]); x++)
        {
            array[y][x] = '.';
        }
    }

    generate_random_walk(array);
    print_array(array);

    return 0;
}

void generate_random_walk(char walk[ROWSIZE][COLSIZE])
{
    //I have tried to use an array to store these variables but there seems to be a problem somewhere i cant seem to figure out
    //this is caused by assigning like currentLoc[0] = nextLoc[0]; this will cause a massive number to placed into currentLoc[0]
    int currentRow = 0, currentCol = 0, nextRow = 0, nextCol = 0;
    //there is a problem with this i can't figure out, it will give a random value
    //if i was to use currentLoc[0] and [1] without creating new variables
    //they would be massive negative or positive numbers everytime i use them.

    srand((unsigned) time(NULL));

    //starting letter
    int step = 'A';
    bool canWalk = true;

    // go from A-Z
    while (canWalk && step <= 'Z')
    {
        //set the letter at the current location

        walk[currentRow][currentCol] = step;

        //get the next letter to represent the next step A-Z


        int random = rand();
        int nextDirection = random % 4;
        ++step;


        //use checkStep to get a new direciton of the next direction already has a char or if its out of range
        bool blocked[4] = {false};
        bool checkStep =  true;

        while (checkStep && canWalk)
        {
            switch (nextDirection)
            {
                //go up one
                case 0:
                    nextRow = currentRow - 1;
                    nextCol = currentCol;
                    break;
                case 1:
                //go right one
                    nextRow = currentRow;
                    nextCol = currentCol + 1;
                    break;
                case 2:
                    nextRow = currentRow + 1;
                    nextCol = currentCol;
                    break;
                case 3:
                    nextRow = currentRow;
                    nextCol = currentCol - 1;
                    break;
            }

            int colSize = COLSIZE;
            int rowSize = ROWSIZE;

            //if not out of bounds or has not visited there
            if (walk[nextRow][nextCol] == '.' && nextRow < colSize && nextCol < rowSize && nextRow >= 0 && nextCol >= 0)
            {
                currentRow = nextRow;
                currentCol = nextCol;
                checkStep = false;
            }
            else
            {
                //this would incrament the random number
                //this will cause it to have the next direction, so if its up then it would be right, then down then left.
                blocked[nextDirection] = true;
                //make sure to repeat the loop so we can check again
                checkStep = true;
                //get a new direction since this one is blocked
                nextDirection = (++random) % 4;

                if (blocked[0] && blocked[1] && blocked[2] && blocked[3])
                {
                    checkStep = false;
                    canWalk = false;
                }
            }
            //end of if/else statments
        }
        //end of while loop
    }
    //end of first while loop
}

void print_array(char walk[ROWSIZE][COLSIZE])
{
    for (int y = 0; y < ROWSIZE; y++)
    {
        for (int x = 0; x < COLSIZE; x++)
        {
            printf("%c ", walk[y][x]);
        }
        printf("\n");
    }
}
