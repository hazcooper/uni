#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "macros.h"
#include "movement.h"
#include "random.c"

int main(int argc, char * argv[])
{
    
    /* checks that the argc argument contains 7 arguments) */

    if(argc != 3)
    {
        printf("usage : ./escape <map_row> <map_col> ");
        return 0;
    }

    /* declaring and initalizaing variables that contain parameters for game and converting from string to integer data type using atoi */

    int rowSize = atoi(argv[1]) + 2; /* adds two extra lines to the grid */
    int colSize = atoi(argv[2]) + 2; /* adds two extra lines to the grid */
    int playerRow = 1;
    int playerCol = 1;
    int goalRow = rowSize - 2;
    int goalCol = colSize - 2;

    
    /* valdiating user command arguments */




   
    /* variable declartion for isSuccess */
    int isSuccess;

    /* allocating size of the game grid based on users number entry when starting game */
    
    char ** gameGrid = malloc2dArrayReturn(rowSize, colSize);

    /* filling gameGrid with X's on the outer edges*/
    
    fillCharArray(gameGrid, rowSize, colSize);

    /* fills the gameGrid with the Player */

    fillPlayer(gameGrid, playerRow, playerCol);
    
    /* fills the gameGrid with the Goal */

    fillGoal(gameGrid, goalRow, goalCol);
    initializeCars(gameGrid, rowSize, colSize);

    do
    {
        
        /* prints gameGrid to screen */

        system("clear");
        printGameGrid(gameGrid, rowSize, colSize);

        /* prints movement controls to screen */

        printMovement();

        /* enables movement around 2d array grid */

        testMovement(gameGrid, &playerRow, &playerCol, &goalRow, &goalCol, &isSuccess);

        /* checks to see if player and goal are on the same square then returns TRUE */

        isSuccess = checkPlayerGoal(gameGrid, &goalRow, &goalCol);

    } 
    while (isSuccess != TRUE );
    /* while loops ends when the winner moves onto the goal, however it does not update with 'P' on the map as it ends.
    I tryed to fix this, but could not come up with a solution. */

    
    /* attempts to frees the memory from the 2d array game grid */
    
    free(gameGrid);


    return 0;
}

