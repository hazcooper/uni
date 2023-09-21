#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "macros.h"
#include<time.h>
/* 
* Function: malloc2dArray
* Import: integer, integer
* Export: none
* Assertion: mallocs a 2d array with the two integer arguments inputted by user to decide the size
 */
void malloc2dArray(int a, int b)
{
    int r;
    /* creates the rows */
    char ** twoD = (char **) malloc(sizeof(char*) * a);

    /* malloc each row to create the columns */
    for(r = 0; r < a; r++)
    {
        twoD[r] = (char *) malloc(sizeof(char) * b);
    }
}

/* 
* Function: malloc2dArrayReturn
* Import: integer, integer
* Export: char ** array
* Assertion: mallocs a 2d array with the two integer arguments inputted by user to decide the size
 */
char ** malloc2dArrayReturn(int a, int b)
{
    int r;

    /* creates the rows */
    char ** twoD = (char **) malloc(sizeof(char*) * a);

    /* malloc each row to create the columns */
    for(r = 0; r < a; r++)
    {
        twoD[r] = (char *) malloc(sizeof(char) * b);
    }
    return twoD;
}

/* 
* Function: printBoundary
* Import: char ** array, integer, integer
* Export: none
* Assertion: prints outer edges of the array displaying X
 */
void printBoundary(char ** arr, int row, int col)
{
    int r, c;
    for(r = 0; r < row; r++)
    {
        for(c = 0; c < col; c++)
        {
            if(r == 0 || c == 0 || r == row - 1 || c == row - 1)
            {
                printf("%c", arr[r][c]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }   
   
}

/* 
* Function: fillcharArray
* Import:  char** array, integer, integer
* Export: none
* Assertion: fills 2d character array with X's on the outer edges and fills the rest with blank spaces
 */
void fillCharArray(char ** arr, int row, int col)
{
    int r, c;
    /*char border = '*';*/ 
    /*char empty = ' ';*/
    
    for(r = 0; r < row; r++)
    {  
        for(c = 0; c < col; c++)
        {
            if(r == 0 || c == 0 || r == row - 1 || c == col -1)
            {
                arr[r][c] = BORDER;
            }
            else if (r % 2 == 0 && r != row - 2) /*Check if the row is even and not last row*/
            {
                arr[r][c] = ROAD; /*Set the cell to represent road*/
            }
            else
            {
                arr[r][c] = EMPTY;
            }   
        }
    }
}

/* 
* Function: fillPlayer
* Import: char** array, integer, integer
* Export: not sure yet
* Assertion: fills the 2d array with player represented as P
 */
void fillPlayer(char ** arr, int row, int col)
{
    /*char player = 'P';*/

    arr[row][col] = PLAYER;
    
}

/* 
* Function: fillGoal
* Import: char** array, integer, integer
* Export: none
* Assertion: Fills the 2d array with the goal represented as G
 */
void fillGoal(char ** arr, int row, int col)
{
    /*char goal = 'G';*/

    arr[row][col] = GOAL;
    
}

/* 
* Function: fillEmpty
* Import: char** array, integer, integer
* Export: none
* Assertion: Fills the 2d array with an empty space
 */
void fillEmpty(char ** arr, int row, int col)
{
    arr[row][col] = EMPTY;
}

void fillRoad(char ** arr, int row, int col)
{
    arr[row][col] = ROAD;
}

/* 
* Function: printGameGrid
* Import: char ** array, integer, integer
* Export: none
* Assertion: prints out the whole game grid (hopefully)
 */
void printGameGrid(char ** arr, int row, int col)
{
    int r, c;
    for(r = 0; r < row; r++)
    {
        for(c = 0; c < col; c++)
        {
            printf("%c", arr[r][c]); 
        }
        printf("\n");
    }   
   
}

/* 
* Function: collapsingFloor
* Import: char ** array, integer, integer
* Export: none
* Assertion: just a placeholder for collapsing floor at the moment
 */
void collapsingFloor(char ** arr, int row, int col)
{
    arr[row][col] = FLOOR;
}

/* 
* Function: printMovement
* Import: none
* Export: none
* Assertion: prints out the controls for player movementa
 */
void printMovement()
{
    printf("Press w to go up\n");
    printf("Press s to go down\n");
    printf("Press a to go left\n");
    printf("Press d to go right\n");
}

void initializeCars(char **arr, int numRows, int numCols) {
    srand(time(NULL)); // Seed the random number generator

    for(int i = 0; i < numRows; i++) {
        if(i % 2 == 0) { // Assuming roads are on even rows
        int carPlaced = 0;
        int randomCol = rand() % (numCols - 2) + 1;
            for(int j = 0; j < numCols; j++) {
                if(arr[i][j] == ROAD && !carPlaced) { // Assuming ROAD is defined as the road character
                    
                    arr[i][randomCol] = (rand() % 2 == 0) ? CAR_LEFT : CAR_RIGHT; // Randomly choose a car direction
                    carPlaced = 1;
                }
            }
        }
    }
}

void moveCars(char **arr, int numRows, int numCols) {
    // Create a temporary array to store the new state of the grid
    char **tempArr = malloc2dArrayReturn(numRows, numCols);
    int i;
    int j;

    // Copy the current state of the grid to the temporary array
    for(i = 0; i < numRows; i++) {
        for(j = 0; j < numCols; j++) {
            tempArr[i][j] = arr[i][j];
        }
    }

    // Iterate through the grid and move the cars based on their direction
    for(i = 0; i < numRows; i++) {
        for(j = 0; j < numCols; j++) {
            if(arr[i][j] == CAR_LEFT) {
                printf("Found a left-facing car at (%d, %d)\n", i, j);
                if(j > 0 && arr[i][j-1] == ROAD) {
                    tempArr[i][j-1] = CAR_LEFT;
                    tempArr[i][j] = ROAD;
                } else if(j > 0) {
                    tempArr[i][j-1] = CAR_RIGHT; // Change direction when hitting a non-road
                    printf("Found a right-facing car at (%d, %d)\n", i, j);
                }
            }
        }
    }
}
